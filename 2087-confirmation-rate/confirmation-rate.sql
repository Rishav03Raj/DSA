# Write your MySQL query statement below
select s.user_id , round(coalesce(c.cnf/c.tt,0),2) confirmation_rate from 
Signups s left join 
(
select user_id , 
count(case when action='confirmed' then 1 end) as cnf,
count(*)  as tt
from Confirmations 
group by user_id
) c
on s.user_id = c.user_id