# os_peertutoring

## How to upload?

### 1. 이 저장소를 Fork 한다.   


### 2. Fork한 자신의 원격저장소를 자신의 로컬 저장소에 clone 한다.   
```
git clone https://github.com/[github_username]/os_peertutoring.git
```

### 3. 실습한 파일을 로컬 저장소에 추가한다.   


### 4. 변경 사항을 add, commit한다.

* git을 처음 설치했을 때 사용자 등록 먼저 필요
```
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
```

* 업로드 할 파일을 각각 선택하고 싶은 경우
```
git add file_name
git commit -m "commit message"
```

* 모든 변경사항을 반영하고 싶은 경우
```
git commit -a -m "commit message"
```

### 5. 자신의 로컬 저장소에 push한다.
```
git push origin master
```
자신의 github username과 password를 입력

### 6. 원래 저장소에 Pull Request를 보낸다.
