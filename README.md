# 운영체제론 또래튜터링

## Member list
|Name|E-mail|ID|
|------|---|---|
|장동건|jdg4661@gmail.com|DG|
|강태연|kang8028@hanyang.ac.kr|TY|
|이지호|jeeho999@naver.com|JH|

## 규칙
* 작성한 코드를 디렉토리에 포함해 업로드할 것
* 개인이 작성한 코드는 반드시 **디렉토리명_ID** 형식의 디렉토리에 포함 ex) bdlist_DG
* 함께 작업한 코드는 **디렉토리명_TEAM** 형식의 디렉토리에 포함

## How to upload?

### 1. 이 저장소를 Fork 한다.   


### 2. Fork한 자신의 원격저장소를 자신의 로컬 저장소에 clone 한다.   
```
git clone https://github.com/[github_username]/os_peertutoring.git
```

### 3. 실습한 파일을 로컬 저장소에 추가한다.   


### 4. 변경 사항을 add, commit한다.

**git을 처음 설치했을 때 사용자 등록 먼저 필요**❗
```
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
```

* 업로드 할 파일이나 폴더를 각각 선택
```
git add file_folder_name
git commit -m "commit message"
```

* 삭제하고 싶을 때는..
```
git rm -r file_folder_name
git commit -m "remove something"
```


### 5. 자신의 로컬 저장소에 push한다.
```
git push origin master
```
자신의 github username과 password를 입력

### 6. 원래 저장소에 Pull Request를 보낸다.
