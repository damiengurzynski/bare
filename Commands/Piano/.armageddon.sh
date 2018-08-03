echo -n "\e[7m" && ls | head -n 1 && echo -n "\e[27m" && ls | tail -n +2 | sed 's/\n/  /g'
