echo $1

echo "无优化"
gcc -o testOptimizing testOptimizing.c 
./testOptimizing $1

echo $'\n'
echo "优化 -O0"
gcc -o testOptimizing -O0 testOptimizing.c 
./testOptimizing $1

echo $'\n'
echo "优化 -O1"
gcc -o testOptimizing -O1 testOptimizing.c 
./testOptimizing $1

echo $'\n'
echo "优化 -O2"
gcc -o testOptimizing -O2 testOptimizing.c 
./testOptimizing $1

echo $'\n'
echo "优化 -O3"
gcc -o testOptimizing -O3 testOptimizing.c 
./testOptimizing $1

