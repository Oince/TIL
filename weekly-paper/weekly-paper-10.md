## 계층별 입력 값 검증

### controller

- bean validation을 통해 입력값의 기본적인 형식을 검사
  - 반드시 존재해야 하는 값인지
  - 문자열의 길이, 숫자의 범위
  - 올바른 형식의 값인지 ex) 타입, 이메일 등의 문자열 형식
- 올바르지 않은 값인 경우에 빠르게 클라이언트에게 알려줘서 UX를 향상시킬 수 있음

### service

- 비즈니스 요구사항에 대해 검증
- 입력값이 핵심 비즈니스 로직에 적합한지 검증함
  - ex) 메세지를 작성할 때, 작성하는 유저가 채널에 등록되어 있어야 함

### repository

- 데이터 무결성 보장
- unique, 외래 키 등 DB 수준의 제약 조건
- DB에서의 검증에 과도하게 의존하면 성능과 UX가 떨어질 수 있음

계층마다 책임을 분리하여 각각의 계층이 위에 설명된 검증 책임을 가지도록 구분하면 중복 검증을 피하면서도 안정성을 확보할 수 있다

 단점으로는 검증 과정이 여러 레이어에 흩어져 있기 때문에 유지 보수가 어렵다는 점이 있다. 또한 약간의 중복 검증이 여전히 존재할 수도 있으며 설계시 검증을 어떤 레이어에서 수행해야 하는지 신중히 결정해야 한다는 것도 고려해야 한다.

### mock

- 특정 메서드가 몇 번 호출되었고, 어떤 파라미터로 호출되었는지 검증할 때 사용하는 가짜 객체

- 테스트 대상의 의존성을 mock으로 대체해서 테스트 진행

- 가짜 객체이기 때문에 실제 로직은 작동하지 않음

- ```java
  @ExtendWith(MockitoExtension.class)
  class UserServiceTest {
  
    @Mock
    UserRepository userRepository;
    @InjectMocks
    UserService userService;
  
    @Test
    @DisplayName("user 생성")
    void createUser() {
      //given
      String email = "test@test.com";
    	String username = "username";
    	String password = "password";
      UserCreateRequest userCreateRequest = new UserCreateRequest(email, username, password);
      User user = User.create(username, email, password);
  
      when(userRepository.save(any(User.class))).thenReturn(user);
  
      //when
      UserResponse response = userService.createUser(userCreateRequest);
  
      verify(userRepository).save(any(User.class));
    }
  ```

- UserService의 외부 의존성인 UserRepository를 mocking하고, save() 메소드가 호출되었는지 테스트함

### stub

- 특정 메서드가 미리 정해진 값만을 호출하도록 할 때 사용

- 보통 mock과 같이 사용되며 외부 의존성의 반환값을 고정하고자 할 때 사용

- mockito에서 when() 으로 구현

- ```java
  @ExtendWith(MockitoExtension.class)
  class UserServiceTest {
  
    @Mock
    UserRepository userRepository;
    @InjectMocks
    UserService userService;
  
    @Test
    @DisplayName("user 생성")
    void createUser() {
      //given
      String email = "test@test.com";
    	String username = "username";
    	String password = "password";
      UserCreateRequest userCreateRequest = new UserCreateRequest(email, username, password);
      User user = User.create(username, email, password);
  
      when(userRepository.save(any(User.class))).thenReturn(user);
  
      //when
      UserResponse response = userService.createUser(userCreateRequest);
  
      verify(userRepository).save(any(User.class));
    }
  ```

- 위와 같은 예시로, UserRepository를 mock으로 설정

- when()을 통해 stubbing하고 thenReturn() 으로 정해진 반환값을 지정함

### spy

- mock과 같은 기능을 하지만 실제 로직을 수행한다는 점이 차이점
- 실제 객체를 사용하기 때문에 그 동작을 그대로 수행함
- 필요한 메서드 호출만 stubbing 하고, 나머지 메서드는 실제 로직을 사용하고자 할 때 사용함
- ```java
  @ExtendWith(MockitoExtension.class)
  class MessageServiceTest {
  
    @Mock
    MessageRepository messageRepository;
    @Spy
    PageResponseMapper pageResponseMapper;
    @InjectMocks
    MessageService messageService;
  
    @Test
    @DisplayName("message 조회")
    void readMessage() {
      UUID channelId = UUID.randomUUID();
      Pageable pageable = PageRequest.of(0, 10);
      Instant createdAt = Instant.now();
      MessageResponse messageResponse = new MessageResponse(
          UUID.randomUUID(),
          createdAt,
          createdAt,
          "message",
          mock(UserResponse.class),
          channelId,
          List.of()
      );
  
      when(messageRepository.findPageByChannelId(channelId, pageable))
          .thenReturn(new SliceImpl<>(List.of(mock(Message.class)), pageable, false));
  
      PageResponse<MessageResponse> pageResponse =
          messageService.readAllByChannelId(channelId, pageable);
  
      assertThat(pageResponse.content().get(0)).isEqualTo(messageResponse);
      assertThat(pageResponse.size()).isEqualTo(pageable.getPageSize());
      assertThat(pageResponse.hasNext()).isFalse();
      assertThat(pageResponse.nextCursor()).isEqualTo(createdAt);
      assertThat(pageResponse.totalElements()).isNull();
    }
  }
  ```
- DTO 변환을 담당하는 PageResponseMapper는 spy로 설정해서 실제 변환 로직을 그대로 수행하게 함

