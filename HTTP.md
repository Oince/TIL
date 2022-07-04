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
