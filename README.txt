Program takes 3 text files: courses.txt, groups.txt, rooms.txt, and gives results in output.txt file

------------------------------------------------------------------------------

courses.txt:

1st row:
n - total number of courses in the file

Then for next row, where 1 <= i <= n:

(5i - 2)'th row
i'th course abbreviature

(5i - 1)'th row
i'th course title

(5i)'th row
Name of professor teaching i'th courses

(5i + 1)'th row
Up to 4 options, indicating number of lecture, tutorial, lab, complab groups for i'th course

------------------------------------------------------------------------------

groups.txt

1st row:
n - total number of groups in the file

Then for next row, where 1 <= i <= n:

(3i)'th row
Name and size of i'th group, separated by space

(3i + 1)'th row
List of course abbreviatures, which the i'th group takes, separated by comma

------------------------------------------------------------------------------

rooms.txt

1st row
n - total number of rooms in the file

Then for next rows, where 1 <= i <= n:

(i + 1)'row
Name and size for i'th room. Additional attributes such as "labs" or "complabs" can be entered. All parameters are comma separated

------------------------------------------------------------------------------

timetable.txt

Contains resulting timetable for the given data