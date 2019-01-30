# File-Management-System-Using-C
THEORETICAL BACKGROUND :-

Literature Review:
1. 'ls' command is used for displaying all the contents (basically files and folders) under the working directory.
2. 'mkdir' command is used for creating a new directory under the working directory.
3. 'cd' command is used for changing the working directory.
4. 'cd /' command is used for changing the working directory to it's root directory.
5. 'touch' command is used for creating a new file under the working directory.
6. 'tree' command is used for displaying the contents of the root directory and sub-directories, and the output takes a graphical form.
7. 'exit' command is used to terminate the program.

Syntax for the Commands:
1. For using 'ls' command just type 'ls' and press Enter key.
2. For using 'mkdir' command, type 'mkdir name_of_directory' and press Enter key.
3. For using 'cd' command, type 'cd name_of_directory' and press Enter key.
4. For using 'cd /' command just type 'cd /' and press Enter key.
5. For using 'touch' command, type 'touch name_of_file.*extension' and press Enter key.
6. For using 'tree' command just type 'tree' and press Enter key.
7. For using 'exit' command just type 'exit' and press Enter key.

Data Structure Used:
We have used the concept of non-linear data structure as the nodes are not linearly arranged (i.e., one after another), in which one link part will hold the directories or files under the present working directory (i.e., *next part) and another link part which will help us in traversing as well as changing the working directory and then create new directories or files in it (i.e., *under part). Each and every node has these two link parts, and can be treated as a directory itself as we can create files and folders in each and every one of them.

*NOTE:
1. If the syntax of the commands mentioned above is not correctly typed while running the program then one error message will be displayed, after that again we can continue with all the commands, i.e., no data will be lost.
2. While using 'cd' command if the directory does not exist, then this code will create that directory and then make that it the working directory.
3. "ROOT" is the name of the root directory used in this program.
4. Only the 7 commands mentioned above along with their specific use can work in this program, other than these commands there are more commands but we have not implemented them in our code, so apart from them no other command will work.
