# DNS

****

**DNS**란 컴퓨터의 ip주소에 이름을 할당한 것  
`getaddrinfo()` 함수를 사용해 DNS 사용  

**getaddrinfo()** 함수 작동 순서   

1. 이름에 대한 IP 주소가 로컬 캐시에 있는지 체크
   - 있으면 그 주소로 접속
2. 없으면 DNS 서버에 요청을 보냄
3. 응답이 오면 그 주소로 접속

보통 ISP에서 DNS 서버를 제공하지만 사설 DNS 서버도 존재함 ex) Google public DNS

## DNS domain hierarchy

도메인 네임은 계층적으로 관리됨  
각각의 노드는 domain 또는 subdomain 이라고 함.  
루트는 **root** 라고 하고 root 도메인 바로 밑에 있는 노드를 **Top-level domain(TLD)**라고 하고, TLD 밑의 노드는 Second-level domain 이라고 함  
TLD에는 다음과 같은 종류가 있음  

- infrastructure TLD
  - .arpa

- generic TLD: 일반 목적
  - .com .net

- Sponsored TLD: 특수 목적
  - .edu .gov .mil. travel .jobs

- Country code TLD: 국가에 할당된 TLD
  - 우리나라의 경우 .kr 사용

- Reserved TLD 
  - .example .test .localhost .invalid


### DNS Zone

**DNS zone**은 관련있는 도메인을 묶는 것  
각각의 zone에는 **Authoritative name server**가 존재해서 DNS 쿼리에 대한 명확한 답을 제공함  
Authoritative name server는 모든 존에 대한 정보를 가지고 있는 **master server** 혹은 master server의 카피본을 가지고 있는 **slave server**가 될 수 있다.  

## DNS Protocol 

client가 hostname에 해당하는 IP 주소를 알기 위해서는 DNS 서버에 DNS query를 보내야 함.  
**DNS 프로토콜**은 UDP를 이용하고 주로 53번 포트를 사용함  
DNS 서버의 IP주소를 모르면 DNS 서비스를 이용할 수 없음  
쿼리의 길이가 길어지면 TCP를 사용하기도 함

절차

1. 클라이언트가 로컬 DNS 서버에 쿼리를 보냄
2. 로컬 DNS 서버가 해당 hostname의 IP주소를 모르면 root DNS 서버에게 쿼리를 보냄
3. root DNS 서버가 IP 주소를 가지고 있을 수 있는 하위 DNS 서버의 주소를 알려줌
4. 하위 DNS 서버로 쿼리를 보냄
5. 하위 DNS 서버에 IP 주소가 있을 경우 응답을 보내주고, 아닐경우 다시 주소를 가지고 있을 수 있는 DNS 서버의 주소를 알려줌
6. IP 주소를 얻을 때 까지 반복
7. IP 주소를 얻으면 클라이언트에게 해당 hostname에 대한 IP 주소를 알려줌

리눅스에서 `dig`명령어를 통해 dns서버에 query를 보낼 수 있음  

```bash
dig @a.root-servers.net www.example.com
```

## DNS Message format

DNS 메세지는 다섯가지 부분으로 나뉨  
<img src = "data:image/png;base64,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">

- Header
  - 메세지의 헤더 부분
- Question
  - 보내는 질문의 정보
- Answer
  - 질문에 대한 답
- Authority
  - 다른 name server의 주소
- Additional
  - 추가적인 정보

### Header

DNS 메세지 헤더는 총 12바이트로 구성됨  
<img src="https://www.oreilly.com/library/view/hands-on-network-programming/9781789349863/assets/346de5c8-e0a1-4694-bee3-2ffd68761f09.png">

| Field   | 의미                                                         |
| :------ | :----------------------------------------------------------- |
| ID      | DNS 메세지를 식별하기 위한 번호                              |
| QR      | 쿼리일 경우 0, 응답일 경우 1                                 |
| Opcode  | 쿼리의 종류, 0은 보통 쿼리, 1은 reverse 쿼리 등을 뜻함       |
| AA      | 응답 메세지에서 DNS 서버가 Authoritative server인지 여부     |
| TC      | 메세지가 너무 길어 TCP로 전송해야 할 경우를 나타내는 비트    |
| RD      | recursion을 사용할 경우 설정                                 |
| RA      | 응답한 서버가 recursion을 지원하는지 여부                    |
| Z       | 사용하지 않는 비트, 0으로 세팅                               |
| RCODE   | 에러 코드  <br />0 - 에러 없음  <br />1 - format error  <br />2 - server failure  <br />3 - name error  <br />4 - not implemented  <br />5 - refused |
| QDCOUNT | question 개수                                                |
| ANCOUNT | answer 개수                                                  |
| NSCOUNT |                                                              |
| ARCOUNT |                                                              |

### Question

question 에는 묻고자 하는 호스트에 대한 정보가 들어간다.  
| Field         | 값                                                   |
| ------------- | ---------------------------------------------------- |
| NAME          | 호스트의 이름                                        |
| QTYPE(16bit)  | DNS record 타입  <br />주로 A(IPv4), AAAA(IPv6) 사용 |
| QCLASS(16bit) | 인터넷을 사용해야 하므로 1로 세팅                    |

name 필드는 특별한 인코딩 규칙이 존재  
.을 구분으로 끊어서 끊긴 길이 이후에 값이 들어감  
길이가 0이면 끝남

ex) www.example.com 일 경우  
3 w w w 7 e x a m p l e 3 c o m 0

### Answer

answer 에는 질의한 호스트에 대한 정보가 들어간다

| Field      | 값                                   |
| ---------- | ------------------------------------ |
| NAME       | question과 동일                      |
| TYPE       | question과 동일                      |
| CLASS      | question과 동일                      |
| TTL(32bit) | 정보가 유지되는 시간                 |
| RDLENGTH   | data의 길이                          |
| RDATA      | data, type에 따라 해석 방법이 달라짐 |

























