# GitHub
--------------------------------------------------

# 1. 基本说明

## 1.1 简介
属于VCS (版本控制系统)
利于: 文件安全(Remote)、版本回退(Checkout Revert)、团队合作(Merge)

## 1.2 术语
- Werkspace 工作区 (放代码的文件来)
- Repository 仓库 (放备份的地方)
- Comnit 提交 (快照)(备份)(记录代码更改)
- Branch 分支 (时间轴)

## 1.3 基本操作
- Init 初始
- Checkout 签出 (如对B节点 checkout,则workspne变为B的状态,HEAD指向B)
- Merge 合并
- Rebase 变基

## 1.4 Git in VSCode
左栏 ![GitInVSCode左栏] : 
- 创建repo: intialize
- commit: 需命名当次提交名称
- 回退: 点某节点右键checkout
- 建分支: 右键某节点添加
- 合并: 先checkout至主分支再右键副分支的节点merge

## 1.5 网址格式
https://github.com/包库主人/仓库名


--------------------------------------------------
--------------------------------------------------
# 2. Git For Windows 配置

## 2.1 登录
```
git config --global user.name "用户名"
git config --global user.email "邮箱@aaa.com"
```

## 2.2 网络问题
```shell
git config --global http.proxy http://127.0.0.1:7890
```

## 2.3 关闭自动转换换行符
```shell
git config --global core.autocrlf false
```


--------------------------------------------------
--------------------------------------------------
# 3. 常用命令
Copy: Ctrl+ Ins \
Paste : Shitt+ Ins
```shell
git init 
# 在当前目录下初始化一个新的Gt仑库

git clone 远程合库网址
# 克隆远程仑库(remote repesitory) 到本地

git add 文件名
# 将工作目录(working directory 电脑文件夹) 中的文件添加刊暂存区,准备提交

git commit -m "提交注释"
# 将暂存区(staging area) 文件提交到本地仓库(local repository)

git status
# 查看工作区和暂存区状态

git branch
# 显示当前仓库的所有分支

git branch -d 分支名
# 删除某分支 (此前自己要在其他分支) (强制删除为 -D)

git push 远程仓库名 分支名
# 将本地仓库的提交推到远程仓库。origin是一般程仓库的默次名称

git push 远程仓库名 分支名 -f
# 强利将本他外支推送到远程仓库,会覆盖远程分支的历史

git push 远程仓库名 --delete 分支名
# 删除Git包库的某一个支

git pull 远程仓库名 分支名
# 拉取远程仓库的最新代码到本地

git checkout 分支名
# 切换到指定的分支 (checkeut -b 创建以其为名的新分支并切换到它)

git merge 分支名
# 将指定分支的代码合并到当前分支

git log
# 查看提交历史记录, 按Q退出

git diff
# 查看当前工作区与暂存区的差异

git fetch
# 从远程仓库获取最新的代码、分支、提交历史, 但不会自动合并或修改当前工作区的分支。检查远程包库的变化, 将变化下载到本地的 origin(默认的远程色库名称) 的分支中

git rebase 远程仓库名 分支名
# 把当前外支的改变在目标分爱上重演, 并加换列目标外支

git rm -r --cached 文件名或文件夹名
# 已提交的文件会被纳入版本控制, 再加在 .gitignore 里会不生效。需要用此命令移除对其的版本控制
```


--------------------------------------------------
--------------------------------------------------
# 4. 操作实例

## 4.1 将电脑上与 Git Bash 终端 同级的所有文件放入远程空仓库:
```shell
git init
git remote add origin 远程仑库URL
git add .
git commit -m "这次提交的注释"
git push origin 主分支名你   # 比如 main 或 master
```

## 4.2 修改提交历史
```shell
git log --oneline

git rebase -i 作为基的提交的7位序号

# 修改提交信息:
# 在打开的页面编辑文本, 将 pick 换为 r

# 修改作者:
git commit --amend --author="用户名 <用户邮箱>" --no-edit
git rebase --continue

# 将修改强制提交:
git push origin main -f
```
![Git修改提交历史合并]
当使用 squash 合并时, 上面的算 previous, 应该把靠下的commit前面的pick替换为s


--------------------------------------------------
--------------------------------------------------
# 5. 使用Commitizen进行提交

## 5.1 配置
#### 在 Windows 配置
1. 安装 Node.js (https://nodejs.org/en/download) (可用 PowerShell 验证是否安装成功)
    ```shell
    node -v
    npm -v
    ```
2. 全局安装 Commitizen
可用PowerShell输入 \
  (其中Windows中的~/代表的是C:/Users/用户名/)
    ```shell
    npm install -g commitizen cz-conventional-changelog
    '{ "path": "cz-customizable" }' | Out-File -FilePath "~/.czrc" -Encoding utf8
    npm i -g cz-customizable
    ```
3. 创建模板
  在工程项目的文件夹内创建 .cz-config.js 文件

#### 在 Linux 配置
1. 下载 Node.js (https://nodejs.org/en/download) 选择自己的版本(比如Linux Binaries (x64)) \
  *(建议别用 sudo apt install, 它装的npm版本很低)*
2. 安装 Node.js (https://github.com/nodejs/help/wiki/Installation) \
  完成 **How to install Node.js via binary archive on Linux** 这节之后先别关窗口, 输入
    ```shell
    echo -e 'export PATH=/usr/local/lib/nodejs/node-'$VERSION'-'$DISTRO'/bin:$PATH' >> ~/.bashrc
    ```
3. 全局安装 Commitizen 并创建模板
  可用PowerShell输入
    ```shell
    npm install -g commitizen cz-conventional-changelog
    echo -e '{ "path": "cz-customizable" }' > ~/.czrc
    npm i -g cz-customizable
    touch .cz-config.js
    ```

## 5.2 自定义模板
  修改 .cz-config.js 内容为: 
    ```
    'use strict';


    module.exports = {

      types: [
        {
          value: '🧹chore',
          name : 'chore:    零碎任务 (如构建 工具 依赖管理)'
        },
        {
          value: '📜docs',
          name : 'docs:     修改文档'
        },
        {
          value: '✨feat',
          name : 'feat:     增加新功能'
        },
        {
          value: '🐞fix',
          name : 'fix:      修复bug'
        },
        {
          value: '🚀perf',
          name : 'perf:     提高程序性能'
        },
        {
          value: '🛠refactor',
          name : 'refactor: 改善代码结构布局'
        },
        {
          value: '⏪revert',
          name : 'revert:   撤回之前的commit'
        },
        {
          value: '🎨style',
          name : 'style:    修改代码格式 (如缩进 空格 换行符 命名约定)'
        },
        {
          value: '📝test',
          name : 'test:     修改测试用例'
        },
        {
          value: '🚧WIP',
          name : 'WIP:      正在进行的半成品'
        },
      ],

      // scopes: [{ name: 'accounts' }, { name: 'admin' }, { name: 'exampleScope' }, { name: 'changeMe' }],

      messages: {
        type: "Select the type of change that you're committing:",
        scope: '\nDenote the SCOPE of this change (optional):',
        customScope: 'Denote the SCOPE of this change:',
        subject: 'Write a SHORT, IMPERATIVE tense description of the change:\n',
        body: 'Provide a LONGER description of the change (optional). Use "|" to break new line:\n',
        breaking: 'List any BREAKING CHANGES (optional):\n',
        footer: 'List any ISSUES CLOSED by this change (optional). E.g.: #31, #34:\n',
        confirmCommit: 'Are you sure you want to proceed with the commit above?',
      },

      allowCustomScopes: true,
      allowBreakingChanges: ["feat", "fix"],
      
      skipQuestions: ['scope']
    };

    // Template
    /*
    module.exports = {
      types: [
        { value: 'feat', name: 'feat:     A new feature' },
        { value: 'fix', name: 'fix:      A bug fix' },
        { value: 'docs', name: 'docs:     Documentation only changes' },
        {
          value: 'style',
          name: 'style:    Changes that do not affect the meaning of the code\n            (white-space, formatting, missing semi-colons, etc)',
        },
        {
          value: 'refactor',
          name: 'refactor: A code change that neither fixes a bug nor adds a feature',
        },
        {
          value: 'perf',
          name: 'perf:     A code change that improves performance',
        },
        { value: 'test', name: 'test:     Adding missing tests' },
        {
          value: 'chore',
          name: 'chore:    Changes to the build process or auxiliary tools\n            and libraries such as documentation generation',
        },
        { value: 'revert', name: 'revert:   Revert to a commit' },
        { value: 'WIP', name: 'WIP:      Work in progress' },
      ],

      scopes: [{ name: 'accounts' }, { name: 'admin' }, { name: 'exampleScope' }, { name: 'changeMe' }],

      usePreparedCommit: false, // to re-use commit from ./.git/COMMIT_EDITMSG
      allowTicketNumber: false,
      isTicketNumberRequired: false,
      ticketNumberPrefix: 'TICKET-',
      ticketNumberRegExp: '\\d{1,5}',

      // it needs to match the value for field type. Eg.: 'fix'
      // scopeOverrides: {
      //   fix: [

      //     {name: 'merge'},
      //     {name: 'style'},
      //     {name: 'e2eTest'},
      //     {name: 'unitTest'}
      //   ]
      // },
      // override the messages, defaults are as follows
      messages: {
        type: "Select the type of change that you're committing:",
        scope: '\nDenote the SCOPE of this change (optional):',
        // used if allowCustomScopes is true
        customScope: 'Denote the SCOPE of this change:',
        subject: 'Write a SHORT, IMPERATIVE tense description of the change:\n',
        body: 'Provide a LONGER description of the change (optional). Use "|" to break new line:\n',
        breaking: 'List any BREAKING CHANGES (optional):\n',
        footer: 'List any ISSUES CLOSED by this change (optional). E.g.: #31, #34:\n',
        confirmCommit: 'Are you sure you want to proceed with the commit above?',
      },

      allowCustomScopes: true,
      allowBreakingChanges: ['feat', 'fix'],
      // skip any questions you want
      // skipQuestions: ['scope', 'body'],

      // limit subject length
      subjectLimit: 100,
      // breaklineChar: '|', // It is supported for fields body and footer.
      // footerPrefix : 'ISSUES CLOSED:'
      // askForBreakingChangeFirst : true, // default is false
    };
    */
    ```
    ( 其中66行后的代码都是模板, 可仿照其格式做出修改, 在不同的工程配置不同的commit格式 )

## 5.3 使用GitBash的提交方式
1. 添加文件, 如 `git add .` 
2. `winpty git cz` (Windows 使用 GitBash 需要用 winpty 保证窗口的交互功能, Linux 可以直接`git cz`) 
3. 使用方向键上下选择commit类型, 回车
![Commitizen选择commit类型]
4. 输入Commit的名称以及详细注释, 标注optional的部分可以直接回车跳过
![Commitizen推送命名]
5. 推送, 如 `git push origin main`\
  效果图: 
![Commitizen效果图]

- 补充说明: 格式理应是
  ```
  <type>(<scope>): <subject>
  <空行>
  <body>
  <空行>
  <footer>
  ```
  但目前还没有分前端后端、用户管理员的需求, 就省略了(<scope>)
  有需要时注释掉第64行的  skipQuestions: ['scope']即可

- 参考资料:\
[优雅地提交你的 Git Commit Message](https://zhuanlan.zhihu.com/p/34223150)\
[Git Commit Log规范推荐](https://zhuanlan.zhihu.com/p/34223150)

 









--------------------------------------------------
--------------------------------------------------






