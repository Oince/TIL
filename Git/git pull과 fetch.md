# pull과 fetch의 차이점

- fetch

  - 원격 저장소에 있는 변경 사항들을 로컬 저장소로 가져옴

    - 커밋, 브랜치 등의 내용을 가져옴

  - 정보만 가져오고 브랜치에 병합하진 않음

  - FETCH-HEAD 파일 생성

    - 원격 저장소의 변경 사항이 저장되는 파일

  - 예시

  - ```bash
    git fetch						# 기본 저장소의 내용 가져옴
    git fetch <remote>				# remote 저장소의 내용 가져옴
    git fetch <remote> <branch>		# remote 저장소의 branch 내용 가져옴
    git fetch --all					# 모든 원격 저장소의 내용 가져옴
    ```

- pull

  - fetch한 후 자동으로 병합까지 진행함

  - fetch + merge와 같음

  - ```bash
    git pull						# 현재 브랜치와 연결된 원격 브랜치의 내용 가져오고 병합
    git pull <remote> <branch>		# remote 저장소의 branch 내용 가져오고 병합
    git pull --ff-only 				# fast-forward인 경우에만 병합
    ```



- fetch를 사용하는 경우
  - 변경 사항을 검토한 후에 병합해야 할 때 ex) 충돌 가능성이 높을 때
- pull을 사용하는 경우
  - 변경 사항을 바로 반영할 때

## 트래킹 브랜치

- 원격 브랜치에서 로컬 브랜치로 switch 하면 자동으로 로컬브랜치가 원격 브랜치와 연결되고, 로컬 브랜치를 원격 브랜치의 트래킹 브랜치로 만든다.

- ```bash
  git switch -c 로컬브랜치 원격브랜치 # 기본 형태
  git switch -t 원격브랜치 		 # 로컬 브랜치 이름 자동 생성
  git switch 로컬브랜치			 # 원격 저장소에 입력한 브랜치의 이름이 딱 하나 있고 로컬에 								   없으면 자동으로 트래킹 브랜치를 생성함
  ```

- 연결된 로컬 브랜치에서 push나 pull 명령을 내리면 자동으로 원격 브랜치의 데이터를 보내거나 가져온다.

- clone하면 자동으로 origin/master와 로컬 master 브랜치를 연결함

- 이미 존재하는 브랜치를 트래킹 브랜치로 만드는 방법은 다음과 같다

- ```bash
  git branch -u <remote-branch> 	# 현재 브랜치를 remote-branch의 트래킹 브랜치로 만듬
  ```

