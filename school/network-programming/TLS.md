# TLS

TLS는 클라이언트와 서버의 통신에 메세지 인증, 기밀성, 가용성등을 제공하는 기술이다.  
Application 계층과 Transport 계층 사이에 존재하는 프로토콜이다  
과거에는 SSL이라고도 불림 

TLS에는 4가지 프로토콜이 있음

- Handshake
- Changeciperspec
- Record
- Alert
  - 에러 처리에 사용

## 과정

### Handshake

<img src="TLS handshake.png">

어떤 암호화 알고리즘을 사용할 지, 인증 키를 어떻게 만들건지 협의하는 단계

- Phase 1
  - 기본적인 정보들과 서로 지원 가능한 암호 알고리즘 공유
- Phase 2
  - Certificate : 서버의 인증서 체인 전송
    - 서버의 인증서를 CA의 공개키로 검증하고, CA의 인증서를 root CA의 공개키로 검증한다
  - ServerKeyExchange: 키 교환 메세지 전송, 여러 방법이 있지만 여기서는 DH 키교환 사용
    - g^s mod p값과, 서명 전송
  - CertificateRequest: 클라이언트의 인증서 요청
  - ServerHelloDone: phase 2의 끝을 알림
- Phase 3
  - Certificate: 클라이언트의 인증서 체인 전송
  - ClientKeyExchange: 키 교환 메세지 전송
  - CertificateVerify: 인증서 인증을 위한 서명값 전송
- Phase 4
  - ChangeCipherSpec: 서로 사용할 암호 알고리즘 확인
  - Finished: 주고 받은 메시지의 해쉬값 확인

handshake가 끝나면 서로 공유한 키로 **Pre-master secert(PM)**이 생성된다.  
PM 값을 key 생성 함수(주로 해쉬함수 사용)에 넣어서 암호화 키와 인증 키를 생성한다.  

### ChangeCipherSpec

ChangeCipherSpec 메세지를 보내 pending 상태에 있던 값을 active 상태로 바꾸는 작업

확인하는 값

- 암호 알고리즘
- MAC 알고리즘
- 암호화 키
- MAC 키
- 초기 벡터 IV

### Record

압축된 데이터와 MAC 키를 해쉬해서 MAC 값을 만들고, 암호화 키를 사용해서 데이터와 MAC 값을 암호화 해서 TLS 페이로드를 만든다.

## OpenSSL

OpenSSL은 SSL/TLS 서비스를 제공해주는 오픈소스 라이브러리이다.

### 사용법

```c
SSL_library_init();
OpenSSL_add_all_algotithms();
SSL_load_error_strings();
```

사용하기 전에 먼저 초기화를 해야한다  
`SSL_library_init()`은 초기화를 하는 코드이다.  
`OpenSSL_add_all_algotithms()`은 사용 가능한 모든 알고리즘을 추가하는 코드이다.  
원하는 알고리즘만 추가할 수도 있다  
`SSL_load_error_strings()`은 에러 스트링을 가져오는 코드이며 필수는 아니다

```c
SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
```

`SSL_CTX_new()`함수로 SSL context를 생성한다.  
SSL context는 초기화 시에 정해놓은 정보들을 저장하는 객체이다.  
SSL 연결 종료시에 메모리 할당을 해제해야 한다.

```c
SSL *ssl = SSL_new(ctx);
SSL_set_tlsext_host_name(ssl, hostname);
SSL_set_fd(ssl, server);
SSL_connect(ssl);
```

`SSL_new()`함수로 SSL 객체를 생성한다.  
`SSL_set_tlsext_host_name()`함수로 서버의 도메인 이름을 설정한다.  
`SSL_set_fd()`함수로 소켓에 ssl을 적용시키고, `SSL_connect()`함수로 서버와 TLS 연결을 맺는다

```c
SSL_write(ssl, buffer, strlen(buffer));
SSL_read(ssl, buffer, sizeof(buffer));
SSL_get_cipher(ssl):
```

`SSL_write()`와 `SSL_read()`로 데이터를 읽고 쓴다  
`SSL_get_cipher()`로 ssl 객체가 사용하는 암호 알고리즘을 가져올 수 있다.

```c
X509 *cert = SSL_get_peer_certificate(ssl);
X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
```

`SSL_get_peer_certificate()`함수로 X509 형식의 인증서를 가져올 수 있다.  
`X509_NAME_oneline()`함수의 인자로 가져오고 싶은 인증서의 정보를 넣으면 그 정보를 가져온다

```c
SSL_shutdown(ssl);
SSL_free(ssl);
SSL_CTX_free(ctx);
```

SSL 객체와 SSL_CTX 객체의 메모리 할당을 해제한다.

