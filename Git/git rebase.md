# Git rebase

merge와 같이 한 브랜치를 다른 브랜치로 합치는 방법이다. 브랜치를 합친다는 점에서 merge와 유사하지만 세부 사항에서 차이가 있다. rebase에 대해 알아보기 전에 merge에 관해서 먼저 알아보자.

## Merge

- merge는 다른 브랜치의 내용을 현재 브랜치로 가져와 합친다.

- 현재 브랜치가 가리키고 있는 커밋이 merge할 브랜치의 조상인 경우 fast-forward 방식으로 merge한다.
  - fast-forward: 단순히 현재 브랜치가 merge할 브랜치와 동일한 커밋을 가리키도록 현재 브랜치를 이동시킴
  - <img src="https://git-scm.com/book/ko/v2/images/basic-branching-4.png">
  - hotfix 브랜치의 조상이 master가 가리키고 있는 c2 커밋이기 때문에 단순히 master 브랜치가 가리키는 커밋을 c4로 수정한다
  - <img src="https://git-scm.com/book/ko/v2/images/basic-branching-5.png">

- 현재 브랜치가 가리키고 있는 커밋이 merge할 브랜치의 조상이 아닌 경우 3-way-merge를 한다
  - 3-way-merge: 각 브랜치를 가리키는 커밋과 그들의 조상 커밋으로 merge하는 것
  
  - 조상 커밋인 base 커밋으로 무엇이 원본인지 판단해서 수정된 것을 merge 커밋에 넣는다.
  
  - 3-way-merge 방식은 merge 성공시 새로운 merge 커밋을 생성해서 해당 브랜치가 새 커밋을 가리키게 한다
  
  - <img src="https://git-scm.com/book/ko/v2/images/basic-merging-1.png">
  
  - master와 iss53을 merge할 경우 c2 커밋을 기반으로 merge 진행 후 새 커밋을 c4 뒤에 붙이고 master 브랜치가 새 커밋을 가리키게 한다
  
  - 만약 c4, c5 커밋이 같은 파일을 수정했을 경우 충돌이 발생한다.
  
    - 충돌이 발생하면 다음과 같은 방법으로 충돌을 해결해야 한다.
  
    - ```bash
      git status #충돌 파일 확인
      
      cat README.md
      <<<<<<< HEAD
      README.txt
      =======
      master branch
      >>>>>>> iss53
      
      # 가운데 선을 기준으로 윗부분은 현재 브랜치의 내용
      # 밑부분은 합치려는 iss53 브랜치의 내용
      
      # 충돌 파일 수정
      vi README.md
      
      #충돌 파일을 추적하게 하게 commit함
      git add README.md
      git commit
      ```
  
- merge가 완료된 브랜치는 삭제해서 상태가 완료되었음을 표시한다.

## Rebase

rebase는 현재 브랜치의 base 커밋을 다른 브랜치가 가리키고 있는 커밋으로 재설정한다.

<img src="https://git-scm.com/book/ko/v2/images/basic-rebase-1.png">

위와 같이 master와 experiment 브랜치가 있을 때 experiment 브랜치를 master 브랜치로 rebase하면 다음 그림과 같이 변한다

<img src="https://git-scm.com/book/ko/v2/images/basic-rebase-3.png">

c4 커밋이 master가 가리키는 c3 커밋을 가리키게 된다. 자세한 처리 과정은 다음과 같다

1. 두 브랜치의 공통 커밋을 찾는다
2. 공통 커밋부터 현재 experiment가 가리키는 커밋까지를 master 브랜치 앞에 붙인다

이후에 master 브랜치에서 experiment 브랜치를 merge하면

<img src="https://git-scm.com/book/ko/v2/images/basic-rebase-4.png">

이렇게 c4 커밋이 master 브랜치의 시작점이 된다.

## 차이점

merge는 기존 브랜치의 히스토리를 보존해서 협업시 히스토리를 추적하기가 용이하다. 또한 충돌 발생시 병합 시점에 한번만 해결하면 된다. 하지만 merge는 브랜치를 병합할 때 새 커밋을 생성한다. 그렇기 때문에 브랜치가 많아지면 많아질수록 커밋 히스토리가 복잡해진다. 

rebase는 merge 커밋을 생성하지 않고, 커밋 히스토리를 깔끔하게 정리할 수 있다는 장점이 있다. 단점은 rebase후 merge시에 충돌이 여러번 발생할 수 있고, 커밋 히스토리를 추척하기 어렵다는 점이다. 또한 원격 저장소에 push한 커밋을 rebase할 경우 base 커밋이 달라져 많은 충돌을 유발할 수 있기 때문에 협업시에는 주의해서 사용해야 한다.

개인적인 생각으로는 로컬 저장소의 내 작업 브랜치에서 작업 후 rebase로 커밋 히스토리를 깔끔하게 정리하고, 상위 브랜치에 merge 하는 것이 안전하게 rebase를 사용하는 방법이라고 생각한다.

