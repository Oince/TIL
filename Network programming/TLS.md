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

## Handshake

<img src="TLS handshake.png">

어떤 암호화 알고리즘을 사용할 지, 인증 키를 어떻게 만들건지 협의하는 단계

- Phase 1
  - 기본적인 정보들과 서로 지원 가능한 암호 알고리즘 공유
- Phase 2
  - Certificate : 서버의 인증서 체인 전송
  - ServerKeyExchange: 키 교환 메세지 전송,  DH 키교환 사용
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

## ChangeCipherSpec

ChangeCipherSpec 메세지를 보내 pending 상태에 있던 값을 active 상태로 바꾸는 작업

확인하는 값

- 암호 알고리즘
- MAC 알고리즘
- 암호화 키
- MAC 키
- 초기 벡터 IV

## Record

압축된 데이터와 MAC 키를 해쉬해서 MAC 값을 만들고, 암호화 키를 사용해서 데이터와 MAC 값을 암호화 해서 TLS 페이로드를 만든다.

