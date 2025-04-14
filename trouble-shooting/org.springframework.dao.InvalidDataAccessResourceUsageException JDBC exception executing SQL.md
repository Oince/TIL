# org.springframework.dao.InvalidDataAccessResourceUsageException JDBC exception executing SQL

docker compose로 스프링 부트와 postgrsql을 띄워서 프로젝트를 진행하던 중에 만난 오류이다.

**docker-compose.yml**

```yaml
services:
  discodeit:
    build: .
    image: discodeit
    ports:
      - "8080:8080"
    environment:
      SPRING_DATASOURCE_URL: ${SPRING_DATASOURCE_URL}
      SPRING_DATASOURCE_USERNAME: ${SPRING_DATASOURCE_USERNAME}
      SPRING_DATASOURCE_PASSWORD: ${SPRING_DATASOURCE_PASSWORD}
    volumes:
      - binary-content-storage:/app/files
    depends_on:
      - postgres

  postgres:
    image: postgres
    ports:
      - "5432:5432"
    environment:
      POSTGRES_PASSWORD: postgres1234
    volumes:
      - postgres-data:/var/lib/postgresql/data
      - ./src/main/resources/init.sql:/docker-entrypoint-initdb.d/01-init.sql

volumes:
  binary-content-storage:
  postgres-data:
```

**init.sql**

```sql
CREATE USER discodeit_user PASSWORD 'discodeit1234';
CREATE DATABASE discodeit WITH OWNER discodeit_user;

GRANT ALL PRIVILEGES ON DATABASE discodeit TO discodeit_user;
GRANT ALL PRIVILEGES ON SCHEMA public TO discodeit_user;

GRANT USAGE ON SCHEMA public TO discodeit_user;
GRANT CREATE ON SCHEMA public TO discodeit_user;
GRANT SELECT, INSERT, UPDATE, DELETE ON ALL TABLES IN SCHEMA public TO discodeit_user;
GRANT USAGE ON ALL SEQUENCES IN SCHEMA public TO discodeit_user;
GRANT EXECUTE ON ALL FUNCTIONS IN SCHEMA public TO discodeit_user;
ALTER DEFAULT PRIVILEGES IN SCHEMA public
    GRANT SELECT, INSERT, UPDATE, DELETE ON TABLES TO discodeit_user;

```

datagrip으로 접속해보니 discodeit_user가 discodeit의 public 스키마에 접근하지 못했다. 권한이 없어서 생긴 문제라고 판단하고 권한을 부여해주었다. 하지만 init.sql에 권한을 전부 주었는데 같은 오류가 발생했다. 

postgres 데이터베이스에서 작업을 수행한 것이 문제였다. discodeit 데이터베이스로 교체한 후에 실행하니 잘 실행되었다.

```sql
CREATE USER discodeit_user PASSWORD 'discodeit1234';
CREATE DATABASE discodeit WITH OWNER discodeit_user;

GRANT ALL PRIVILEGES ON DATABASE discodeit TO discodeit_user;
GRANT ALL PRIVILEGES ON SCHEMA public TO discodeit_user;

-- discodeit으로 DB를 교체하는 psql 쿼리
\c discodeit
GRANT USAGE ON SCHEMA public TO discodeit_user;
GRANT CREATE ON SCHEMA public TO discodeit_user;
GRANT SELECT, INSERT, UPDATE, DELETE ON ALL TABLES IN SCHEMA public TO discodeit_user;
GRANT USAGE ON ALL SEQUENCES IN SCHEMA public TO discodeit_user;
GRANT EXECUTE ON ALL FUNCTIONS IN SCHEMA public TO discodeit_user;
ALTER DEFAULT PRIVILEGES IN SCHEMA public
    GRANT SELECT, INSERT, UPDATE, DELETE ON TABLES TO discodeit_user;

```







