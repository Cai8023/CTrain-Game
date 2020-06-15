# CTrain-Game

## 四川师范大学-计算机科学学院-C实训作业

## Git部分

### 初始化操作

1. 在全英文路径下建立一个文件夹，再在这个文件夹内新建文件夹`/game`
2. 进入该文件夹，右击鼠标 ==》 Git Bash Here  ==》输入 `git init` 初始化一个仓库
3. 输入 `git remote add gamerepo git@github.com:Cai8023/CTrain-Game.git` 就可以链接到这个仓库
   *gamerepo* 是在本地的仓库名，可以自取
4. `git clone git@github.com:Cai8023/CTrain-Game.git` ，然后项目就克隆到本地啦

### 新建分支

已经在 github 那边创建了各自名字的分支，所以大家只需要在本地建立相应分支就好啦

首先，默认分值是 *master* ，这个分支我们一般不做改动

1. 输入`git branch dev` ，这样就创建了一个dev分支，这个分支用于大家合并代码
2. 输入`git checkout dev` ，这样就切换到了dev分支，就可以进行合并代码（如何合并在下面介绍）
3. 输入`git checkout -b 名字缩写` ，这样就**创建并切换**了一个你自己名字的分支（checkout -b 相当于上面两条命令的合成）

### 上传下载代码

大家平常就在自己分支上进行代码的编写

如何保证在自己的分支上呢？输入`git branch `，然后就可以看了

* 上传代码 `git push 仓库名 分支名`，比如 git push gamerepo ck（上传前请切换到目标分支）
* 下载代码 `git pull 仓库名 分支名` ，比如 git pull gamerepo ck

==注意== 大家在对dev分支进行上传自己部分的代码前，都请一定先 pull 一次代码解决冲突

### 合并代码

大家平常就在自己的分支上进行代码的编写

当自己部分代码完成可以整合到总代码时

1. `git checkout dev`，切换到dev分支
2. `git merge 自己的分支`，将自己部分的代码合并到本地的 dev 分支上
3. `git pull 仓库名 dev`，下载 github 上的dev分支代码，进行冲突处理
4. `git push 仓库名dev`，将处理后的代码 上传到 dev 分支
5. `git checkout 自己的分支`，切换到自己的分支继续写bug

## QT部分

### 如何添加资源文件

1. 取消 resource 的注释， 打开 game.pro 文件

2. 在最下面部分，取消`RESOURCE +=\ res.qrc` 部分的注释，然后 `ctrl+S`保存修改，这样你就会在左侧看见 Resource 文件夹了，就可以往里面添加资源文件了（注意需要提前将资源文件放在项目目录下的/res里）

3. 然后记得 **编译** 一次

4. 将 `RESOURCE +=\ res.qrc` 部分重新注释上

5. 编译 rcc 文件，进入项目目录下，在终端输入 `rcc -binary .\res.qrc -o res.rcc`

## 如何新建ui界面

如果有些界面，比如登录界面，显示排名界面需要用到 ui 界面

则在 QT 中右击项目文件夹 ==》 add new ==》Qt ==》 Qt 设计师界面类/Qt Designer Form

即可