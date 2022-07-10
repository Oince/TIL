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

### 종류

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

### 속성

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

## HTTP Method 활용

### 데이터 전송

- 정적 데이터 조회
  - 이미지나 정적 텍스트 문서를 조회
  - GET 지원
- 동적 데이터 조회
  - 쿼리 파라미터 사용
  - 필터나 정렬 조건에 주로 사용함
  - GET 지원
- HTML Form을 통한 데이터 전송
  - HTML의 form 태그를 이용해서 데이터 전송
  - GET 사용시 URL에 쿼리 스트링으로 전송함
  - POST 사용시 쿼리 스트링과 유사한 형식(key=value)을 메세지 바디에 넣어서 전송
    - POST 요청시 Content-Type 헤더는 application/x-www-form-urlencoded로 설정됨
  - 파일을 같이 전송할 경우  Content-Type 헤더를 multipart/form-data로 설정하고 boundary에 구분자를 지정
  - GET, POST 지원

- HTTP API를 이용한 데이터 전송
  - 메세지 바디에 데이터를 넣어서 전송
  - 서버끼리의 통신이나, 앱 클라이언트, ajax통신에 사용
  - 주로 JSON형식을 사용한다

### 설계 방법

- POST 기반 등록
  - 서버가 리소스의 URI를 생성하고 관리함
  - 클라이언트가 등록될 리소스의 URI를 모르는 경우
  - 서버가 Location헤더에 새로 생성된 리소스의 URI를 알려줌
  - 이때 POST 요청을 보낸 URI를 **Collection** 이라고 함
    - 컬렉션은 서버가 관리하는 리소스 디렉토리
  - ex) POST /members
- PUT 기반 등록
  - 클라이언트가 직접 리소스의 URI를 지정해야함 
  - 클라이언트가 리소스의 URI를 알고 있어야 함
  - 클라이언트가 관리하는 리소스 저장소가 **Store**
  - ex) PUT /files
- 컨트롤 URI
  - 동사로 된 리소스 경로를 사용하는 것
  - HTTP 메서드로 동작을 나타내기 어려운 경우에 사용

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
  - **404 Not Found** - 요청 리소스를 찾을 수 없음7
    - 클라이언트가 권한이 부족한 리소스에 접근했을 때 해당 리소스를 숨기기 위해 사용하기도 함 
- 5xx - 서버 오류
  - 같은 요청을 보냈을 때 성공할 수도 있음
  - 500번대 오류는 정말 필요한 상황에만 사용
  - **500 Internal Server Error** - 서버 내부 오류
  - **503 Service Unavailable** - 서비스 이용 불가
    - 일시적인 과부하 혹은 예정된 작업으로 요청을 처리할 수 없음

## HTTP Header

### 표현 헤더

- Content-Type: 표현 데이터의 형식
  - text/html, application/json 등
- Content-Encoding: 표현 데이터 인코딩
  - 표현 데이터를 압축하기 위해 사용
  - gzip, defalte, identuty(압축 안함) 등
- Content-Language: 표현 데이터의 자연 언어
  - ko, en, en-US 등등의 자연 언어를 나타냄
- Content-Length: 표현 데이터의 길이
  - Transfer-Encoding을 사용할 때는 사용하면 안됨

### 협상 헤더

협상 헤더는 요청시에만 사용함

- Accept: 클라이언트가 선호하는 미디어 타입
- Accept-Charset: 클라이언트가 선호하는 문자 인코딩
- Accept-Encoding: 클라이언트가 선호하는 압축 인코딩
- Accept-Language: 클라이언트가 선호나는 자연 언어

협상 시 **Quality Value**를 사용하여 우선순위를 지정할 수 있음  
0~1까지 지정 가능하고 숫자가 클수록 높은 우선순위를 가짐, 생략시 1로 간주함  
ex) Accept-Language: ko-KR, ko;q=0.9, en-US;q=0.8, en;q=0.7

1. ko-KR(생략시 1로 간주)
2. ko(0.9)
3. en-US(0.8)
4. en(0.7)

우선순위 지정이 없으면 보다 구체적인 것이 높은 우선순위를 가지고, 구체적인 것을 기준으로 미디어 타입을 맞춘다  
ex) Accept: text/*;q=0.3, text/html;q=0.7; \*/\*;q=0.5

1. text/html(0.7)
2. image/jpeg(0.5)
3. text/plain(0.3)

### 전송 방식

- 단순 전송
  - Content-Length 헤더에 보내는 메세지 바디의 길이를 지정
- 압축 전송
  - Content-Encoding 헤더에 압축 정보를 지정하고 압축된 메세지 바디의 길이를 Content-Length에 지정
- 분할 전송
  - 용량이 큰 파일을 전송하거나, 길이를 알 수 없을 때, 분할해서 전송하기 위해 사용
  - Transfer-Encoding: chunked 헤더로 지정함
  - 메세지 바디가 이번에 전송할 데이터의 크기 + \r\n + 전송할 데이터의 형식을 가짐
  - 끝을 나타내는 형식은 0 \r\n 
- 범위 전송
  - 데이터의 일부만 요청할 때 사용
  - 클라이언트에서 Range 헤더 필드에 받고 싶은 데이터의 범위를 지정(ex) Range: bytes=1001-2000)
  - 서버에서는 Content-Range 헤더 필드에 전송하는 데이터의 범위와 전체 파일의 길이를 보냄(ex) Content-Range: bytes=1001-2000 / 2001)

### 일반 헤더

- From: 유저 에이전트의 이메일 정보
- Referer: 이전 웹 페이지 주소
  - 요청에서 사용
- User-Agent: 클라이언트 어플리케이션 정보
  - 요청에서 사용
- Server: 서버의 소프트웨어 정보
  - 프록시 서버가 아닌 원래 서버의 정보
  - 응답에서 사용
- Date: 메세지가 발생한 시간과 날짜
  - 응답에서 사용

### 특별 정보

- Host: 요청한 호스트(도메인) 정보
  - 요청에서 사용함
  - 하나의 서버가 여러 도메인을 처리하거나 여러 도메인이 적용되어 있을 때 혼란을 막기 위해 사용
  - 필수적으로 사용해야 함
- Location: 페이지 리다이렉션
  - 3xx의 응답 코드의 결과에 Location 헤더가 있으면 그 위치로 자동 리다이렉트함
  - 201의 경우에는 새로 생성된 리소스의 URI가 들어 있음
- Allow: 허용 가능한 HTTP 메서드
  - URI는 존재하지만 해당하는 HTTP 메서드가 존재하지 않을 경우에 사용
  - 405 응답의 Allow 헤더 필드에 지원하는 HTTP 메서드를 포함해야 함
- Retry-After: 유저 에이전트가 다음 요청을 하기까지 기다려야 하는 시간
  - 503 응답코드 사용시 포함
  - 날짜 표기일 경우 지정 날짜 부터 서비스 사용 가능
  - 초단위 표기일 경우 해당 시간이 지난 후 부터 서비스 사용 가능
- Authorization: 클라이언트 인증 정보를 서버에 전달
- WWW-Authenticate: 리소스 접근 시 필요한 인증 방법 정의
  - 401 응답 코드 사용시 포함
  - 필요한 인증 방법을 알려줌

### 쿠키

HTTP는 stateless하기 때문에 클라이언트의 상태를 저장하지 않는다.  
이를 해결하기 위해 쿠키를 사용한다.  
서버가 쿠키를 만들어서 전송할 때 **Set-Cookie** 헤더 필드에 값을 넣어서 전송하고 클라이언트에서는 **Cookie** 헤더 필드에 값을 넣어서 전송한다  
쿠키는 로그인 세션을 관리할 때 주로 사용된다  
쿠키 정보는 항상 서버에 전송되기 때문에 추가적인 네트워크 트래픽을 유발한다.  
따라서 최소한의 정보만을 사용하고, 보안에 민감한 데이터는 저장하지 않는다

쿠키는 다음과 같은 값을 가질 수 있다

- expires
  - 만료일 지정, 만료일이 지나면 쿠키 삭제
- max-age
  - 초 단위 시간 지정, 지정된 시간이 지나면 쿠키 삭제
- domain
  - 쿠키에 접근할 수 있는 도메인 설정
  - 값을 명시하면 명시한 문서 기준 도메인 + 서브 도메인까지 포함
  - 생략하면 현재 문서 기준 도메인만 적용
- path
  - 쿠키에 접근할 수 있는 경로 지정
  - 지정된 경로 + 하위 경로에서 접근 가능
  - 일반적으로 루트로 지정
