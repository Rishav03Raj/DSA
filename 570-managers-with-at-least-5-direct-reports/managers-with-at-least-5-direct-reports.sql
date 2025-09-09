# Write your MySQL query statement below
select e.name from employee e 
join (
select managerId
 from employee where managerId is not null
group by managerId 
 having count(*)>=5
) e1 on e.id  = e1.managerId;