Class=$1
CLASS=$(echo $Class | tr 'a-z' 'A-Z')
folder=AReply/
HPP=incs/$folder/$Class.hpp
CPP=srcs/$folder/$Class.cpp
cp incs/$folder/SampleHeaderreply.hpp $HPP
sed -i '' "s/NAME/$CLASS/g" $HPP # $CPP
sed -i '' "s/Name/$Class/g" $HPP # $CPP

sed -i '' "s/#NEW_REPLY_HERE/$Class.hpp \\\#NR/g" Makefile
gsed -i "s/#NR/\n\t\t\t\t#NEW_REPLY_HERE/g" Makefile

sed -i '' "s=//insert_here=insert(\&$Class);//NR=g" srcs/ReplyCreator.cpp
gsed -i "s=//NR=\n\t//insert_here=g" srcs/ReplyCreator.cpp

sed -i '' "s=//reply_here=$Class $Class;//NR=g" incs/ReplyCreator.hpp
gsed -i "s=//NR=\n\t//reply_here=g" incs/ReplyCreator.hpp

sed -i '' "s=//include_here=# include \"$Class.hpp\"//NR=g" incs/AReply/Includereply.hpp
gsed -i "s=//NR=\n//include_here=g" incs/AReply/Includereply.hpp