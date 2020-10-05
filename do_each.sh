for f in $(file art/* | awk -F ': ' '/data/{print $1}'); do
  if [[ ! $f =~ "vt" ]]; then
    echo -e "\033[r"
    clear
    cat $f | ./a.out | less
  fi
done
