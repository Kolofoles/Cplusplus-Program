**# Grocery-Item-Tracker**

**Reason for the Program**

The purpose of this program is to allow a user to multiple ways to view data from a text file regarding grocery store item sales.
There are four menu options:
  1) Search and find the number of times a particular grocery item sold in a given day. This returns a numeric value if the item was found.
  2) Print the frequency of sales for all items in the file. The items are displayed alphabetically, with the armount sold displayed next to the item.
  3) Print the same frequency information with the numerical values represented as a histogram.
  4) Quit the program.

This program also creates a frequency.dat file, where each item in the map is listed in alphabetical order alongside the quantity of purchases.

**Validating Input**

Invalid inputs are handled simply with a switch statement. As user input to interact with the menu is numerical, setting the default to handle
all other inputs was an easy approach to this issue. 

**Areas to be Improved**

Formatting for whitespace could be improved. 
Currently, the amount of whitespace used to create buffers for the histogram is a manually entered value. While it wasn't an issue with the current text file, it would be best to change how whitespace is calculated to better suit text files with varying length of item names.
This could be done by finding the length of the longest item name and adding one blank space between the last character of the item and the 
number / symbol used to display quantities.

**Challenges and Skills Learned**

The task I had the most difficulty handling was getting the data into a map, which would then get updated as each new value in the text file was read.
Maps were something I had never used before, so learning how to work with one was quite confusing in the beginning. I read through the section in the
textbook a few times, and reviewed the test code and examples provided multiple times to understand syntax, as well as understand how information
was being manipulated with maps. After a while of review I managed to successfully implement a map in this program and I'm really proud of it! I'm excited to have added another tool to my belt as I continue learning how to write code.

During this project, I also became more comfortable with things like clearing the system screen, clearing the error state of cin, and discarding invalid inputs. I had a general understanding of how to go about it before, but this program helped solidify that knowledge.

**Maintainability**

This program has in-line comments sprinkled throughout that explain what nearly every section of code does. The goal was to allow somebody with no technical knowledge to be able to read through the code and understand what each section is doing. All functions and variables are given detailed names to allow future developers to understand exactly what does what, and see how everything interacts with each other.
