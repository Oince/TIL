# Docker

## 사용하는 이유

- 이식성이 좋다
  - 특정 프로그램을 다른 컴퓨터 환경에서도 쉽게 설치하고 실행할 수 있음
- 환경에 독립적으로 실행되기 때문에 다른 프로그램과 충돌이 발생하지 않음
- 버전이나 환경 설정, os 등등의 것들과 상관없이 항상 일관된게 프로그램을 설치, 실행할 수 있음

## docker란?

- 컨테이너를 사용하여 각각의 프로그램을 분리된 환경에서 실행하게 하는 도구

### 컨테이너

- 하나의 컴퓨터 환경에서 여러개의 다른 **독립적인 컴퓨터 환경**을 구성해서 프로그램을 별도로 설치하고 실행할 수 있도록 함
- 컴퓨터 안의 미니 컴퓨터를 만든다고 생각하면 편함
- 컨테이너 == 미니 컴퓨터
- 컨테이너가 있는 컴퓨터를 호스트 컴퓨터라고 함

### 이미지

- 프로그램을 실행하는데 필요한 설치 과정, 설정, 버전 정보 등을 포함하고 있음
- 즉 프로그램을 실행하는데 필요한 모든 정보를 담고 있음

## 기본 사용법

- ```bash
  docker pull [이미지명:태그명]
  ```

  - 이미지를 다운받는 명령어
  - dockerhub에서 이미지를 다운받음
    - dockerhub: 깃허브처럼 이미지를 저장하고 다운받을 수 있는 저장소
  - 태그는 이미지의 특정 버전 의미
    - 태그 생략시 최신 버전인 latest이 자동 지정됨

- ```bash
  docker images
  ```
  
  - 모든 이미지 조회
  - docker image ls와 동일한 명령어
  - 옵션
    - -q: 이미지의 id만 조회함
  
- ```bash
  docker image rm [이미지명 or 이미지 ID]
  ```

  - 이미지 삭제 명령어

  - 옵션

    - -f: 중지된 컨테이너에서 사용되고 있는 이미지도 강제 삭제(실행중인 컨테이너의 이미지는 삭제 불가)

  - 꿀팁

    - ```bash
      docker image rm $(docker images -q)
      ```

    - 이렇게 작성하면 존재하는 모든 이미지를 삭제할 수 있음

- ```bash
  docker create [이미지명]
  ```
  - 이미지로 컨테이너를 생성하는 명령어
  - 로컬에 이미지가 존재하지 않는다면 자동으로 dockerhub에서 받아옴
  - 실행은 시켜주지 않으므로 따로 실행해야 함
  
- ```bash
  docker start [컨테이너명 or 컨테이너 id]
  ```

  - 컨테이너 실행하는 명령어

- ```bash
  docker run [이미지명 or 이미지 id]
  ```

  - 컨테이너 생성 + 실행까지 한번에 하는 명렁어 (create + start)
  - 옵션
    - -d: 백그라운드 실행
    - --name: 컨테이너 이름 지정
    - -p: 포트 포워딩 설정
      - ex) -p 8080:80 : 호스트의 8080 -> 컨테이너의 80 으로 포트 포워딩

    - -e: 환경 변수 설정
    - -v: 볼륨 설정

- ```bash
  docker ps
  ```

  - 실행중인 컨테이너 조회
  - 옵션
    - -a: 중지된 컨테이너 까지 모두 조회

- ```bash
  docker stop [컨테이너명]
  ```

  - 컨테이너 중지

- ```bash
  docker kill [컨테이너명]
  ```

  - 컨테이너 강제 중지

- ```bash
  docker rm [컨테이너명]
  ```

  - 컨테이너 삭제
  - 실행중인 컨테이너는 삭제할 수 없음
  - 옵션
    - -f: 실행중인 컨테이너도 삭제함

- ```bash
  docker logs [컨테이너명]
  ```

  - 실행중인 컨테이너의 로그 확인

  - 옵션

    - -f: 로그를 포그라운드에서 실시간으로 확인 가능
    - --tail: 최근 n줄의 로그만 확인

  - 꿀팁

    - ```bash
      docker logs --tail 0 -f [컨테이너명]
      ```

    - 이렇게 하면 명령어 입력 시점부터의 로그만 볼 수 있음

- ```bash
  docker exec -it [컨테이너명] [명령]
  ```

  - 컨테이너의 내부에 bash로 접속하는 명령어
  - -it 옵션을 적용하지 않으면 1회성 명령만 날리고 끝남 


## Volume

데이터베이스를 컨테이너로 띄워서 잘 사용하고 있다가 새 기능을 추가해야 한다고 생각해보자. docker는 컨테이너에 새 기능을 추가하려면 새 이미지를 만들어서 컨테이너를 새로 띄워야 한다. 새 컨테이너를 만들어서 기존의 컨테이너를 교체하면, 기존의 데이터가 전부 삭제된다. 컨테이너의 데이터가 삭제되면 안되는 경우 볼륨을 사용해서 데이터를 보존한다.

볼륨은 컨테이너에서 데이터를 영속적으로 저장하기 위한 방법이다. 데이터베이스같은 데이터가 유실되어서는 안되는 상황에 주로 사용된다. docker run으로 컨테이너를 생성할 때 -v 옵션으로 볼륨을 지정할 수 있다.

```bash
# docker run -v [호스트의 절대 경로]:[컨테이너의 절대 경로]
docker run -d -p 5433:5432 -e POSTGRES_PASSWORD=pwd123 -v /home/oince/docker/postgres-data:/var/lib/postgresql/data postgres
docker run -d -p 3306:3306 -e MYSQL_ROOT_PASSWORD=pwd123 -v /home/oince/docker/mysql-data:/var/lib/mysql mysql
```

> DB를 컨테이너로 생성할 때, 필수적으로 지정해야 하는 환경 변수들이 존재한다. 받고자 하는 이미지의 Dockerhub에 환경 변수에 대한 설명이 존재한다. 또한 데이터가 저장되는 경로 역시 Dockerhub에 설명되어 있으니 문서를 참고하여 적절한 경로를 지정해야 한다.

호스트 경로의 디렉토리가 존재하지 않거나 빈 디렉토리인 경우, 컨테이너 경로의 파일을 지정한 호스트 디렉토리로 복사한다. 만약 호스트 디렉토리에 파일이 존재할 경우, 컨테이너 디렉토리 안의 파일을 삭제하고 호스트 디렉토리의 파일을 복사해서 붙여넣는다.

이 부분에서 주의해야 할 점이 있다. 디렉토리와 그 안의 파일을 미리 만들어두면, 컨테이너를 생성할 때 컨테이너의 디렉토리가 복사되는 것이 아닌 호스트의 파일이 복사가 된다. 결과적으로 컨테이너에 원래 존재해야 할 파일들이 전부 삭제되고 미리 준비해둔 파일만 존재하게 되어 오류가 발생하게 된다. 볼륨을 사용할 때는 먼저 디렉토리를 만들어두지 말고 존재하지 않는 디렉토리를 지정해서 컨테이너의 파일이 복사되도록 해야 한다.

또한 기존에 존재하는 볼륨에 환경 변수 값을 바꿔서 다른 컨테이너를 연결한 경우에 바뀐 환경 변수가 적용되지 않는 현상이 발생한다. 그 이유는 볼륨이 생성될 때는 원래 환경 변수 값으로 생성되어 저장되었기 때문이다. 그래서 다른 환경 변수를 지정하여 컨테이너를 생성한다고 하더라도 볼륨은 기존의 환경 변수를 저장하고 있기 때문에 적용되지 않는다. 환경 변수나 다른 설정을 바꾸고 싶다면 볼륨을 삭제하고 새로 만들거나 컨테이너 내부에서 직접 변경해야 한다.

## Dockerfile

Dockerfile은 docker 이미지를 만들게 해주는 파일이다. Dockerfile을 이용해서 나만의 이미지를 만들 수 있다.

Dockerfile의 명령어는 다음과 같다

- FROM [이미지]
  - 베이스 이미지를 생성하는 명령어
  - FROM에 지정된 이미지를 기반으로 추가적인 설정을 통해 이미지를 만들 수 있음
  - JDK, Ubuntu, nginx등의 이미지를 초기 이미지로 설정하고, 그 위에 설정을 덧붙여 새 이미지를 만들 수 있음
- COPY [호스트에서 복사할 파일의 경로] [컨테이너에서 파일이 위치할 경로]
  - 호스트의 파일을 복사해서 컨테이너로 전달하는 명령어
  - 와일드 카드를 사용해서 파일을 지정할 수도 있음
  - 특정 파일은 복사하고 싶지 않다면 `.dockerignore` 파일에 지정해서 무시할 수 있음
- ENTRYPOINT [명령문]
  - 컨테이너가 시작될 때 실행되는 명령어
  - 주로 실행시키고 싶은 프로그램을 실행하는 명령어를 작성함
- RUN [명령문]
  - 이미지 생성 과정에서 필요한 명령어를 실행시킴
  - ENTRYPOINT는 컨테이너가 시작할 때 필요한 명령어를 실행시키지만 RUN은 이미지 생성 과정에 필요한 명령어를 실행시킴
- ENV [환경변수 이름]=[값]
  - 환경 변수를 설정하는 명령어
- WORKDIR [작업 디렉토리 경로]
  - 말 그대로 작업 디렉토리를 지정함
  - 이후의 모든 명령은 지정한 경로 아래에서 실행됨
- EXPOSE [포트 번호]
  - 지정된 포트를 외부에 노출시키겠다는 의미
  - -p 옵션으로 포트포워딩을 해주지 않으면 의미가 없음
  - -P 옵션을 주면 호스트의 랜덤 포트와 지정된 포트를 연결해줌
  

```dockerfile
FROM openjdk:17-jdk

WORKDIR /app

COPY build/libs/*SNAPSHOT.jar app.jar

EXPOSE 8080

ENTRYPOINT ["java", "-jar", "/app.jar"]
```

스프링부트 프로젝트를 docker 띄우는 Dockerfile의 예시다. openjdk 17을 base 이미지로 지정하고 WORKDIR을 /app으로 지정했다. 빌드된 파일을 컨테이너의 app.jar로 복사하고 ENTRYPOINT를 통해 java -jar /app.jar 명령어를 실행해 스프링부트 프로그램을 실행한다.

Dockerfile을 빌드하면 이미지를 생성할 수 있다.

```bash
#docker build -t my-server [Dockerfile 경로]
$ docker build -t my-server .
$ docker images
REPOSITORY      TAG       IMAGE ID       CREATED          SIZE
my-server   latest    8c60eb601975   10 minutes ago   279MB
```

> 이미지중 태그에 alpine이 붙은 것들이 있다. 이는 핵심적인 부분만 포함시켜 용량을 줄인 경량화 버전이다.

## docker compose

docker compose는 여러개의 docker 컨테이너들을 하나의 서비스로 정의하고 묶음으로 관리할 수 있도록 도와주는 도구이다. 컨테이너 여러개를 관리하기가 더 쉽고, docker run같은 복잡한 명령어 대신 compose 파일에 미리 적어두고 docker compose up 명령어 하나면 컨테이너를 만들고 실행할 수 있다.

자주 사용하는 명령어

- docker compose pull
  - compose.yml에 정의된 이미지가 없으면 dockerhub에서 다운받고, 있으면 업데이트함
- docker compose up
  - compose.yml에서 정의한 컨테이너들을 실행한다
  - -d: 백그라운드 실행
  - --build: 이미지를 새로 빌드하고 컨테이너를 실행
- docker compose ps
  - compose로 실행된 컨테이너들을 조회
  - -a: 정의된 모든 컨테이너 조회
- docker compose logs
  - compose로 정의된 모든 컨테이너의 로그를 모아서 출력
- docker compose down
  - compose로 실행된 모든 컨테이너들을 중지 & 삭제

밑은 spring boot와 mysql, redis를 docker compose로 구성한 설정 파일이다.

```yaml
# application.yml
spring:
  datasource:
    url: jdbc:mysql://my-db:3306/mydb
    username: root
    password: pwd1234
    driver-class-name: com.mysql.cj.jdbc.Driver
  data:
    redis:
      host: my-cache-server
      port: 6379
```

```yaml
# compose.yml
# 컨테이너에 띄울 service들을 지정
services:
  # my-server라는 이름으로 컨테이너를 생성
  my-server:
    # 현재 경로에 위치한 Dockerfile을 이용해서 이미지 생성
    build: .
    # 포트 지정
    ports:
      - "8080:8080"
    # 지정된 컨테이너들이 띄워져야 이 컨테이너가 실행됨
    depends_on:
      my-db:
        # 띄워졌다는 기준은 healthy 체크
        condition: service_healthy
      my-cache-server:
        condition: service_healthy
  # mysql을 my-db라는 이름으로 컨테이너로 만듬
  my-db:
    # mysql 이미지 사용. 없으면 자동으로 dockerhub에서 가져옴
    image: mysql
    # 컨테이너 생성에 필요한 환경 변수 지정
    environment:
      MYSQL_ROOT_PASSWORD: pwd1234
      MYSQL_DATABASE: mydb
    # 볼륨 지정
    volumes:
      - ./mysql_data:/var/lib/mysql
    ports:
      - "3306:3306"
    # health 체크
    healthcheck:
      # mysqladmin ping 명령어를 수행해서 서버가 살아있는지 확인.
      # 5초마다 실행하고 10번 연속으로 실패하면 unhealthy 상태로 됨
      test: ["CMD", "mysqladmin", "ping"]
      interval: 5s
      retries: 10

  my-cache-server:
    image: redis
    ports:
      - "6379:6379"
    healthcheck:
      test: ["CMD", "redis-cli", "ping"]
      interval: 5s
      retries: 10
```

application.yml 파일에서 datasource의 url이 my-db로 지정되어 있다. 이를 localhost로 하게 되면 어떻게 될까? 컨테이너는 호스트 os와 격리되어 있기 때문에 my-db에 접근하지 못한다. 대신 컨테이너 내부의 3306 포트로 접근하게 되고, my-server 컨테이너 내부의 3306번 포트에는 아무것도 없으므로 연결이 실패하고 오류가 발생해서 컨테이너가 죽어버린다. 이를 해결하기 위해서 locahost 대신 연결하고자 하는 컨테이너의 이름을 지정한다. docker가 내부적으로 가상 브릿지를 통해 컨테이너끼리 통신을 지원하는데, 컨테이너 이름을 docker가 특정 ip 주소로 매핑하여 컨테이너끼리 통신할 수 있도록 한다.
