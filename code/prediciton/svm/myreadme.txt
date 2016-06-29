
java -classpath libsvm.jar svm_train <arguments>
java -classpath libsvm.jar svm_predict <arguments>
java -classpath libsvm.jar svm_toy
java -classpath libsvm.jar svm_scale <arguments>

java -classpath libsvm.jar svm_train -s 3 -t 2 -c 0.03125 -g 0.00003051 amazonDataScale 

 java -classpath libsvm.jar svm_predict amazonTestScale amazonDataScale.model amazonPredict 

java -classpath libsvm.jar svm_scale amazonNew.txt >amazonNewScale

/usr/local/bin/gnuplot

python grid.py -log2c -10,10,1 -log2g -10,10,1  -gnuplot /usr/local/bin/gnuplot -svm_train /Users/Wuyang/ -v 3 amazonDataScale

cd /Users/Wuyang/Desktop/mal/libsvm-3.20/tools/