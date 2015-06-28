#用于测试字符串匹配程序kmp.c的正确性
#测试方式是，随机生成主字符串和模式字符串，分别用kmp.c和StringMatch.java进行字符串匹配，对比两个结果是否相同
#author:guozheng
#2015/06/15

function randomString {
        # if a param was passed, it's the length of the string we want
        if [[ -n $1 ]] && [[ "$1" -lt 20 ]]; then
                local myStrLength=$1;
        else
                # otherwise set to default
                local myStrLength=8;
        fi

        local mySeedNumber=$$`date +%N`; # seed will be the pid + nanoseconds
        local myRandomString=$( echo $mySeedNumber | md5sum | md5sum );
        # create our actual random string
        myRandomResult="${myRandomString:2:myStrLength}"
}


function randomString2 {
        # if a param was passed, it's the length of the string we want
        if [[ -n $1 ]] && [[ "$1" -lt 20 ]]; then
                local myStrLength2=$1;
        else
                # otherwise set to default
                local myStrLength2=8;
        fi

        local mySeedNumber2=$$`date +%N`; # seed will be the pid + nanoseconds
        local myRandomString2=$( echo $mySeedNumber2 | md5sum | md5sum );
        # create our actual random string
        myRandomResult2="${myRandomString2:2:myStrLength2}"
}


gcc -o kmp kmp.c
javac StringMatch.java

for NUM in `seq 1 1 10000`
do

echo $NUM     >&2

echo -e "\n"
echo $NUM

randomString 10;
echo $myRandomResult;

randomString2 2;
echo $myRandomResult2;

pos1=`./kmp $myRandomResult $myRandomResult2`
echo $pos1
pos2=`java StringMatch $myRandomResult $myRandomResult2`
echo $pos2

if [ $pos1 -eq $pos2 ]
then
    echo "相同"
else
    ehco "不相同"
    break
fi


done
