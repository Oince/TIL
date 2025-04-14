# static 초기화 순서

static은 위에서 순서대로 초기화 됨

오류 코드

```java
public class FileUserService implements UserService {

    private static final FileUserService fileUserService = new FileUserService();
    private static final Path filePath = Paths.get(System.getProperty("user.dir"), "users");

    private FileUserService() {
        init();
    }

    public static FileUserService getInstance() {
        return fileUserService;
    }

    private static void init() {
        if (!Files.exists(FileUserService.filePath)) {
            try {
                Files.createDirectories(FileUserService.filePath);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
```

이렇게 하면 init()의 if문에서 NPE 발생함. 이유는 static 은 위에서 순서대로 초기화 되는데, FileUserService 인스턴스를 생성하려고 할 때 생성자가 호출되는데 이때 filePath는 아직 초기화가 되지 않은 상태임. 초기화 안되면 null이기 때문에 NPE 발생함.

new FileUserService() 에서 생성자 호출 -> init 호출 -> filePath 초기화 순서임

해결하려면 static 필드의 초기화 순서를 지정해줘야함

```java
public class FileUserService implements UserService {

    private static final FileUserService fileUserService = new FileUserService();
    private static final Path filePath;

    static {
        filePath = Paths.get(System.getProperty("user.dir"), "users");
        init();
    }

    private FileUserService() {}

    public static FileUserService getInstance() {
        return fileUserService;
    }

    private static void init() {
        if (!Files.exists(FileUserService.filePath)) {
            try {
                Files.createDirectories(FileUserService.filePath);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
```

위와 같이 수정하면 filePath가 먼저 초기화되고, 이후에 init 메서드를 실행하는 것이 보장되기 때문에 NPE가 발생하지 않음.

초기화 순서 : 기본값(기본형의 경우 0, 객체면 null) -> 명시적 초기화(이꼴 옆에 명시한 값) -> 초기화 블럭