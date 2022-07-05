# HTTP

**HTTP**는 TCP 위에서 작동하는 텍스트 기반 client-server 프로토콜이며 주로 80번 포트를 사용한다.  
최근에는 보안 기능이 추가된 TLS 기반 HTTPS를 사용하고 HTTPS는 443 포트를 사용

HTTP는 html, text, 이미지, 음성, 영상파일, json, xml등 다양한 형태를 주로 받을 수 있음  
현재 UDP를 기반으로 한 HTTP/3버전이 개발중

## URI

URI는 uniform resource identifier의 약자로 자원을 식별하는 방식이다  
URN과 URL 두가지 방식이 있다

- URN
  - 자원의 이름(name) 으로 식별하는 방식
- URL
  - 자원의 위치(location)으로 식별하는 방식

주로 URL 방식을 많이 사용한다.  

### URL

URL은 7가지 부분으로 나뉜다

```
scheme://[userinfo@]host[:port][/path][?query][#fragment]
예시)https://www.google.com:443/search?q=hello&hl=ko
```

- 프로토콜 : https
  - http, https, ftp 등의 프로토콜

- userinfo
  - URL에 사용자 정보를 포함에서 인증
  - 거의 사용하지 않음

- 호스트 이름: www.google.com
  - 도메인명 또는 ip주소 사용 가능

- 포트 번호 : 443
  - http는 80, https는 443포트가 기본값, 기본값인 경우 생략 가능
- path: search
  - 리소스의 경로
- query string: q=hello&hl=ko
  - key=value 형태
  - ?으로 시작하고 &로 추가할 수 있음
- fragment
  - html 내부 북마크 등에 사용 ex)위키피디아

## 특징

HTTP는 stateless, conntectionless 두가지 특징이 있음

### stateless

서버가 클라이언트의 상태를 보존하지 않는 특성

- 장점: 서버의 확장성이 높음
- 단점: 클라이언트에 추가 데이터 전송을 요구함 ex) 쿠키

### connectionless

서버가 클라이언트와의 연결을 유지하지 않는 특성

- 장점: 서버 자원을 효율적으로 사용할 수 있음
- 단점: 지속적인 TCP 3-way handshake 오버헤드 발생
  - 단점 해결을 위해 HTTP/1.1버전부터 연결을 끊지 않고 재사용하는 **persistent connection**이 제공됨

## HTTP Message

HTTP 메세지는 3가지로 나뉘고, header와 body 사이는 CRLF로 구분

- start line
  - 요청 메세지일 경우 HTTP 메서드, 요청 대상, HTTP 버전
  - 응답 메세지일 경우 HTTP 버전, 상태 코드, 이유 문구
- header
  - HTTP 메세지에 대한 메타 데이터
  - `field-name: field-value` 형식
  - 각각의 라인은 CRLF로 구분
- body
  - 실제 전송하는 데이터

## HTTP Method

URI는 리소스만 식별하고 리소스를 대상으로 하는 행위를 HTTP method로 구분한다.

- GET: 리소스 조회
  - 데이터는 query를 통해 전달
  - 메세지 바디를 사용할 수 있지만 권장되지 않음 
- HEAD
  - GET과 같지만 메세지 바디를 제외하고 반환함
- POST: 요청 데이터 처리, 주로 등록에 사용
  - 메세지 바디를 통해 데이터 전달
  - 새 리소스를 생성하거나 요청 데이터를 처리할 때 사용
- PUT: 리소스를 대체함, 있으면 대체 없으면 생성
- PATCH: 리소스 부분 변경
- DELETE: 리소스 삭제

HTTP method의 속성

- 안전(safe)
  - 호출해도 리소스를 변경하지 않는 속성
  - GET 메소드가 해당
- 멱등(idenmpotent)
  - 여러번 호출해도 결과가 달라지지 않는 속성
  - GET, PUT, DELETE 해당
  - POST는 해당하지 않음
  - 자동 복구 매커니즘 등에 사용
- 캐시 가능(cacheable)
  - 결과 리소스를 캐시해서 사용하는 속성
  - GET, HEAD, POST, PATCH 가 해당하지만 실제로는 GET, HEAD 정도만 사용 

## HTTP 상태 코드

상태 코드는 클라이언트가 보낸 요청의 처리 상태를 응답 메세지에서 알려주는 기능이다  
클라이언트가 모르는 상태 코드을 받았을 경우 상위 상태 코드로 변환해서 처리한다

- 1xx - 거의 사용하지 않음
- 2xx - 요청을 성공적으로 처리함
  - **200 OK** - 요청 성공
  - **201 Created** - 새로운 리소스가 생성됨
    - 생성된 리소스는 Location 헤더 필드로 식별
  - **202 Accepted** - 요청이 접수되었으나 처리되지 않음
  - **204 No Content** - 요청이 성공적으로 수행되었지만 응답 본문에 보낼 데이터가 없음
- 3xx - 요청을 완료하기 위해 유저 에이전트의 추가 조치 필요
  - 웹 브라우저는 3xx응답의 헤더에 Location 헤더가 있으면 그 위치로 자동 이동
  - 영구 리다이렉션 - 특정 리소스의 URI가 영구적으로 이동
    - **301 Moved Permanently** - 요청 메서드가 GET으로 바뀌고 본문이 제거될 수 있음
    - **308 Permanent Redirect** - 요청 메서드와 본문이 유지됨
  - 일시적 리다이렉션 - 리소스의 URI가 일시적으로 변경
    - **302 Found** - 요청 메서드가 GET으로 바뀌고 본문이 제거될 수 있음
    - **303 See Other** - 요청 메서드가 GET으로 변경
    - **307 Temporary Redirect** - 요청 메서드와 본문이 유지됨
    - **PRG 패턴**
      - POST 요청 이후에 다른 페이지로 Redirect-GET 요청을 하는 패턴
      - 새로고침으로 인한 중복 주문 등을 방지함
  - 기타 리다이렉션
    - **304 Not Modified** - 리소스가 수정되지 않음 
      - 로컬 PC에 저장된 캐시를 재사용함
      - 메세지 바디가 포함되지 않음
      - 조건부 GET, HEAD 요청시 사용
- 4xx - 클라이언트 오류
  - 클라이언트의 요청이 잘못되었을 경우
  - 같은 요청을 보내면 항상 실패함
  - **400 Bad Request** - 잘못된 요청으로 서버가 요청을 처리할 수 없음
    - 요청 구문, 메세지 등의 오류
  - **401 Unauthorized** - 해당 리소스에 대한 인증이 되지 않았음
    - 응답에 WWW-Authenticate 헤더와 함꼐 인증 방법 설명
  - **403 Forbidden** - 서버가 요청을 이해했지만 승인을 거부함
    - 인증은 되었지만 접근 권한이 불충분한 경우 사용
  - **404 Not Found** - 요청 리소스를 찾을 수 없음
    - 클라이언트가 권한이 부족한 리소스에 접근했을 때 해당 리소스를 숨기기 위해 사용하기도 함 
- 5xx - 서버 오류
  - 같은 요청을 보냈을 때 성공할 수도 있음
  - 500번대 오류는 정말 필요한 상황에만 사용
  - **500 Internal Server Error** - 서버 내부 오류
  - **503 Service Unavailable** - 서비스 이용 불가
    - 일시적인 과부하 혹은 예정된 작업으로 요청을 처리할 수 없음
