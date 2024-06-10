# 1. minishell

이 프로젝트는 Bash를 참고하여 POSIX shell을 구현합니다.

# 2. 실행 방법

minishell을 컴파일 하기 위해 GNU의 라이브러리인 readline이 필요합니다.
> brew install readline@8.1

루트에 (all, clean, fclean, re)규칙을 제공하는 `Makefile`이 있습니다. 이를 통해 소스 코드를 컴파일 하여 `minishell`프로그램을 생성합니다.
> make all

* `minishell` 프롬프트 실행
> ./minishell

# 4. 허용 함수

* For the Mandatory
1. `open` on \<unistd.h>
2. `close` on \<unistd.h>
3. `read` on \<unistd.h>
4. `write` on \<unistd.h>
5. `unlink` on \<unistd.h>
6. `fork` on \<unistd.h>
7. `dup` on \<unistd.h>
8. `dup2` on \<unistd.h>
9. `pipe` on \<unistd.h>
10. `execve` on \<unistd.h>
11. `getcwd` on \<unistd.h>
12. `chdir` on \<unistd,h>
13. `isatty` on \<unistd.h>
14. `ttyname` on \<unistd.h>
15. `ttyslot` on \<unistd.h>
16. `errno` on \<errno.h>
17. `printf` on \<stdio.h>
18. `strerror` on \<string.h>
19. `malloc` on \<stdlib.h>
20. `free` on \<stdlib.h>
21. `getenv` on \<stdlib.h>
22. `exit` on \<stdlib.h>
23. `kill` on \<signal.h>
24. `signal` on \<signal.h>
25. `opendir` on \<dirent.h>
26. `closedir` on \<dirent.h>
27. `readdir` on \<dirent.h>
28. `tcgetattr` on \<term.h>
29. `tcsetattr` on \<term.h>
30. `tgetent` on \<term.h>
31. `tgetflag` on \<term.h>
32. `tgetnum` on \<term.h>
33. `tgetstr` on \<term.h>
34. `tgoto` on \<term.h>
35. `tputs` on \<term.h>
36. `ioctl` on \<sys/ioctl.h>
37. `wait3` on \<sys/wait.h>
38. `wait4` on \<sys/wait.h>
39. `wait` on \<sys/wait.h>
40. `waitpid` on \<sys/wait.h>
41. `stat` on \<sys/stat.h>
42. `lstat` on \<sys/stat.h>
43. `fstat` on \<sys/stat.h>
44. `readline` on \<readline/readline.h>
45. `rl_on_new_line` on \<readline/readline.h>
46. `rl_replace_line` on \<readline/readline.h>
47. `rl_redisplay` on \<readline/readline.h>
48. `add_history` on \<readlien/history.h>

# 5. Features

1. 쉘의 전체 흐름은 다음과 같습니다: `사용자 입력에서 환경 변수 확장 -> 확장된 입력을 청크로 토큰화 -> 실행`.
3. 멀티 파이핑, 멀티 리디렉션 가능.
4. Heredoc은 입력에서 중복될 수 없습니다.
5. $? 사용 가능.
6. 사용자 입력의 quotes 처리, 리디렉션, 파이프가 제대로 형성되지 않은 경우 구문 오류 발생.
7. `\`, `;` 등의 특수 문자는 지원되지 않지만 `\\` 는 파일 이름으로 사용할 수 있음.
8. Ctrl + C, Ctrl + D, Ctrl + \는 Bash와 동일하게 구현.
9. Readline 라이브러리를 사용하여 vim과 같은 편집 지원.
10. `add_history` 함수를 사용한 히스토리 관리. 따라서 키보드의 화살표 키를 사용할 수 있음.
11. 여러 내장 명령어가 구현됨. (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`)

# 7. Demo