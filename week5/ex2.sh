
while : 
do
	if ln ex2.txt ex2.lock; then
	    end=$(tail -n 1 < ex2.lock)
	    ((end = end + 1))
	    echo "$end" > ex2.lock
	    rm ex2.lock
	fi
done


