-- Table: Transactions

-- +----------------+---------+
-- | Column Name    | Type    |
-- +----------------+---------+
-- | id             | int     |
-- | country        | varchar |
-- | state          | enum    |
-- | amount         | int     |
-- | trans_date     | date    |
-- +----------------+---------+
-- id is the primary key of this table.
-- The table has information about incoming transactions.
-- The state column is an enum of type ["approved", "declined"].
-- Table: Chargebacks

-- +----------------+---------+
-- | Column Name    | Type    |
-- +----------------+---------+
-- | trans_id       | int     |
-- | trans_date     | date    |
-- +----------------+---------+
-- Chargebacks contains basic information regarding incoming chargebacks from some transactions placed in Transactions table.
-- trans_id is a foreign key to the id column of Transactions table.
-- Each chargeback corresponds to a transaction made previously even if they were not approved.
 

-- Write an SQL query to find for each month and country: the number of approved transactions and their total amount, the number of chargebacks, and their total amount.

-- Note: In your query, given the month and country, ignore rows with all zeros.

-- Return the result table in any order.

-- The query result format is in the following example.

 

-- Example 1:

-- Input: 
-- Transactions table:
-- +-----+---------+----------+--------+------------+
-- | id  | country | state    | amount | trans_date |
-- +-----+---------+----------+--------+------------+
-- | 101 | US      | approved | 1000   | 2019-05-18 |
-- | 102 | US      | declined | 2000   | 2019-05-19 |
-- | 103 | US      | approved | 3000   | 2019-06-10 |
-- | 104 | US      | declined | 4000   | 2019-06-13 |
-- | 105 | US      | approved | 5000   | 2019-06-15 |
-- +-----+---------+----------+--------+------------+
-- Chargebacks table:
-- +----------+------------+
-- | trans_id | trans_date |
-- +----------+------------+
-- | 102      | 2019-05-29 |
-- | 101      | 2019-06-30 |
-- | 105      | 2019-09-18 |
-- +----------+------------+
-- Output: 
-- +---------+---------+----------------+-----------------+------------------+-------------------+
-- | month   | country | approved_count | approved_amount | chargeback_count | chargeback_amount |
-- +---------+---------+----------------+-----------------+------------------+-------------------+
-- | 2019-05 | US      | 1              | 1000            | 1                | 2000              |
-- | 2019-06 | US      | 2              | 8000            | 1                | 1000              |
-- | 2019-09 | US      | 0              | 0               | 1                | 5000              |
-- +---------+---------+----------------+-----------------+------------------+-------------------+

select
    isnull(sub1.month, sub2.month) month,
    isnull(sub1.country, sub2.country) country,
    isnull(sub1.approved_count, 0) approved_count,
    isnull(approved_amount, 0) approved_amount,
    isnull(sub2.chargeback_count, 0) chargeback_count ,
    isnull(sub2.chargeback_amount, 0) chargeback_amount
from(
    select
    left(trans_date , 7) month,
    country,
    sum( iif(state = 'approved', 1, 0)) approved_count,
    sum(iif(state = 'approved', amount, 0)) approved_amount 
    from transactions t
    where t.state = 'approved'
    group by left(trans_date , 7), country
) sub1
full outer join (
    select 
        sum(t.amount) chargeback_amount,
        t.country,
        count(1) chargeback_count ,
        left(c.trans_date, 7) month
    from Chargebacks  c
    inner join transactions t
        on t.id = c. trans_id
    group by left(c.trans_date, 7), country
) sub2
    on sub1.month = sub2.month
    and sub1.country = sub2.country
order by sub1.month, sub2.month

