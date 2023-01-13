-- Table: Customer

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | customer_id | int     |
-- | product_key | int     |
-- +-------------+---------+
-- There is no primary key for this table. It may contain duplicates.
-- product_key is a foreign key to Product table.
 

-- Table: Product

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | product_key | int     |
-- +-------------+---------+
-- product_key is the primary key column for this table.
 

-- Write an SQL query to report the customer ids from the Customer table that bought all the products in the Product table.

-- Return the result table in any order.

-- The query result format is in the following example.

 

-- Example 1:

-- Input: 
-- Customer table:
-- +-------------+-------------+
-- | customer_id | product_key |
-- +-------------+-------------+
-- | 1           | 5           |
-- | 2           | 6           |
-- | 3           | 5           |
-- | 3           | 6           |
-- | 1           | 6           |
-- +-------------+-------------+
-- Product table:
-- +-------------+
-- | product_key |
-- +-------------+
-- | 5           |
-- | 6           |
-- +-------------+
-- Output: 
-- +-------------+
-- | customer_id |
-- +-------------+
-- | 1           |
-- | 3           |
-- +-------------+
-- Explanation: 
-- The customers who bought all the products (5 and 6) are customers with IDs 1 and 3.


-- solution 1 -- 5575 ms

declare @product numeric

select @product = count(1)
from product

select 
customer_id
from customer c
group by customer_id
having count(distinct product_key) = @product

-- soltuion 2  - 2744 ms

declare @product numeric

select @product = count(1)
from product

select
a.customer_id
from ( 
    select 
    customer_id,
    product_key
    from customer c
    group by customer_id, product_key
) a
group by a.customer_id
having count(a.product_key) = @product