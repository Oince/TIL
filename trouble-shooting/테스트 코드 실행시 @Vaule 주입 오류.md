# 테스트 코드 실행시 @Vaule 주입 오류

## 오류코드

```bash
./gradlew clean build

> Task :test

DiscodeitApplicationTests > contextLoads() FAILED
    java.lang.IllegalStateException at DefaultCacheAwareContextLoaderDelegate.java:180
        Caused by: org.springframework.beans.factory.UnsatisfiedDependencyException at ConstructorResolver.java:804
            Caused by: org.springframework.beans.factory.BeanCreationException at ConstructorResolver.java:657
                Caused by: org.springframework.beans.BeanInstantiationException at SimpleInstantiationStrategy.java:199
                    Caused by: software.amazon.awssdk.core.exception.SdkClientException at SdkClientException.java:130

OpenJDK 64-Bit Server VM warning: Sharing is only supported for boot loader classes because bootstrap classpath has been appended
2025-04-14 21:51:15.529 [SpringApplicationShutdownHook]  INFO org.springframework.orm.jpa.LocalContainerEntityManagerFactoryBean - Closing JPA EntityManagerFactory for persistence unit 'default'
```

## 발생 상황

aws s3에 관한 환경 변수들을 세팅해놓고 @Value로 주입받아서 s3와 연결하는 코드를 작성하였다. docker compose로 빌드 후 실행하니 빌드 과정에서 위와 같은 오류가 발생했다. 혹시나 해서 로컬 환경에서 gradlew로 빌드해봐도 같은 오류가 발생했다. 오류 로그를 확인해보니 다른 테스트는 전부 통과하였는데 @SpringBootTest가 붙은 테스트만 통과하지 못했다. 테스트를 빼고 빌드할 경우 정상적으로 빌드되는 것을 확인했다. 

## 원인

도커로 띄울 때만 환경변수를 세팅하도록 한게 문제였다. gradle은 빌드할 때 테스트 코드를 기본적으로 실행한다. @SpringBootTest가 붙은 테스트를 실행하면 모든 빈을 생성하게 되는데, 이때 @Value로 지정된 값도 같이 주입된다. 하지만 설정된 환경 변수가 없으니 오류가 발생하는게 당연하다. 테스트를 빼고 빌드했을 때 오류가 나지 않았던 것은 빌드 과정에서는 테스트 이외의 코드를 실행하지 않기 때문이다. 다른 프로파일로 실행하면 똑같은 오류가 발생한다.

## 해결 방법

주입받을 설정 값이 없어서 발생한 문제이니 test 프로파일에 더미 설정값을 추가하니 오류가 해결되었다.

### 환경 설정 파일

```yaml
# application.yml
spring:
  application:
    name: discodeit
  datasource:
    driver-class-name: org.postgresql.Driver
  jpa:
    database: postgresql
    open-in-view: false
    hibernate:
      ddl-auto: none
  servlet:
    multipart:
      max-file-size: 10MB
      max-request-size: 30MB

discodeit:
  storage:
    type: ${STORAGE_TYPE:local} # local | s3
    local:
      root-path: ${STORAGE_LOCAL_ROOT_PATH:files}
    s3:
      access-key: ${AWS_S3_ACCESS_KEY}
      secret-key: ${AWS_S3_SECRET_KEY}
      region: ${AWS_S3_REGION}
      bucket: ${AWS_S3_BUCKET}
      presigned-url-expiration: ${AWS_S3_PRESIGNED_URL_EXPIRATION:600}

```

```yaml
spring:
  datasource:
    driver-class-name: org.h2.Driver
    url: jdbc:h2:mem:testdb;MODE=PostgreSQL
    username: sa
    password:
  jpa:
    properties:
      hibernate:
        format_sql: true
# 더미 설정 값 추가
discodeit:
  storage:
    type: local # local | s3
    local:
      root-path: files
    s3:
      access-key: accsee-key
      secret-key: secret-key
      region: ap-northeast-2
      bucket: discodeit-binary-content-storage-wjh
      presigned-url-expiration: 600
```

