/*
* Project 3 Create
*
* Author: Eli Billinger
*/

--Step 1 Create the table
drop table if exists schedule;
create table schedule(
 term	TEXT,
 course_id TEXT,
 section TEXT,
 title TEXT,
 instructor TEXT,
 days TEXT,
 begin_time TIME
);

--Step 2 Insert the data
insert into schedule (term,course_id,section,title,instructor,days,begin_time) values ('Fall', 'MATH201', 'B', 'PROBABILITY & STATISTICS', 'Munson, Ashlyn', 'TR', '11:00');
insert into schedule (term,course_id,section,title,instructor,days,begin_time) values ('Fall', 'CSCI262', 'B', 'DATA STRUCTURES', 'Painter-Wakefield, Christopher', 'MWF', '13:30');
insert into schedule (term,course_id,section,title,instructor,days,begin_time) values ('Fall', 'CSCI358', 'A', 'DISCRETE MATHEMATICS', ' ', 'TR', '9:30');
insert into schedule (term,course_id,section,title,instructor,days,begin_time) values ('Fall', 'MATH225', 'C', 'DIFFERENTIAL EQUATIONS', 'Strong, Scott', 'MWF', '16:00');

--Step 3 Fix errors
update schedule set begin_time = '13:00' where course_id = 'CSCI262';

--Step 4 Create another table
drop table if exists transcript;
create table transcript(
 term TEXT,
 course_id TEXT,
 title TEXT,
 grade TEXT,
 credits NUMERIC(4,2),
 quality_points NUMERIC(4,2)
);

--Step 5 add the data
insert into transcript (term,course_id,title,credits) select term,course_id,title,3.0 from schedule;

--Step 6 Enter grades
update transcript set grade = 'A', quality_points = 12.0 where course_id = 'MATH201';
update transcript set grade = 'B', quality_points = 9.0 where course_id = 'CSCI262' or course_id = 'CSCI358';
update transcript set grade = 'A-', quality_points = 11.1 where course_id = 'MATH225';

--Step 8 Drop the old schedule	
drop table schedule;

--Step 9 recreate and populate new schedule
create table schedule as select term, course_id, section, title, instructor, days, begin_time from project3.catalog where CRN IN (12048, 11153, 12379, 10866, 10134, 12704);

--Step 10 fix errors
delete from schedule where course_id = 'MATH332';
