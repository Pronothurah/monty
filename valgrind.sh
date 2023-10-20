clear
for f in monty_project/task_$1/*.sh; do
  bash "$f" 
done