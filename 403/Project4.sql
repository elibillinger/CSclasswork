/*
* Project 4
*
* Author: Eli Billinger
*/

--1. How many Stanford university graduates are there?
Select count(first) from pioneers join schools on pioneers.school_id = schools.id where schools.name = 'Stanford University';

--2. What is the earliest birth year of any pioneer in our data?
Select MIN(birth) from pioneers;

--3. How many pioneers have no higher degrees listed?
Select count(first) from pioneers where pioneers.degree is null;

--4. How many pioneers have first names the same length as their last names?
Select count(first) from pioneers where length(first) = length(last);

--5. For each level of highest degree earned by our pioneers (Doctorate, Masters, Bachelors, none), how many of our pioneers earned a degree at that level?
Select degree,count(first) from pioneers group by degree order by count(degree) desc;

--6. What countries listed in schools have more than 2 schools, and how many do they have?
Select country,count(name) from schools group by country having count(name) > 2 order by count(name) desc;

--7. Give an approximate average lifespan (in years) of the deceased pioneers in our database.
Select round(avg(death-birth)) from pioneers;

--8. In what two years were exactly 5 of our pioneers born?
Select birth from pioneers group by birth having count(first) = 5;

--9. What is the maximum number of awards won by a pioneer in our data? 
Select count(pioneer_id) from pioneers_awards_xref group by pioneer_id having count(pioneer_id) = (select max(mycount) from (select pioneer_id, count(pioneer_id) mycount from pioneers_awards_xref group by pioneer_id) as mycount);

--10. Who is the youngest pioneer, and what year were they born?
Select first,last,birth from pioneers where birth = (select max(birth) from pioneers);

--11. What awards (awarding organization and award name) did Donald Knuth win?
Select name,awarded_by from pioneers_awards_xref join pioneers on pioneers_awards_xref.pioneer_id = pioneers.id join awards on pioneers_awards_xref.award_id = awards.id where first = 'Donald' and last = 'Knuth';

--12. What are the first and last names of every pioneer in our data that won the Presidential Medal of Freedom, and what were they known for? Order by year awarded
Select first, last,known_for from pioneers_awards_xref join pioneers on pioneers_awards_xref.pioneer_id = pioneers.id join awards on pioneers_awards_xref.award_id = awards.id where name = 'Presidential Medal of Freedom' order by year;

--13. Provide Lynn Conway's school name and highest degree, along with the award she won.
Select schools.name,degree,awards.name from pioneers join pioneers_awards_xref on pioneers_awards_xref.pioneer_id = pioneers.id join awards on pioneers_awards_xref.award_id = awards.id join schools on pioneers.school_id = schools.id where first = 'Lynn' and last = 'Conway';

--14. Which pioneers went to school in the same country they were from and won exactly 2 awards, and what school did they attend?
Select first,last,schools.name from pioneers join pioneers_awards_xref on pioneers_awards_xref.pioneer_id = pioneers.id join awards on pioneers_awards_xref.award_id = awards.id join schools on pioneers.school_id = schools.id where pioneers.country = schools.country group by first,last,schools.name having count(pioneers_awards_xref.pioneer_id) = 2;

