select
   left(trans_date , 7) month,
   country,
   count(1) trans_count ,
   sum( iif(state = 'approved', 1, 0)) approved_count ,
   sum(amount ) trans_total_amount,
   sum(iif(state = 'approved', amount, 0)) approved_total_amount 
from transactions t
group by left(trans_date , 7), country