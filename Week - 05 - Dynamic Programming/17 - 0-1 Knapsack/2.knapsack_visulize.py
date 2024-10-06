# https://recursion.vercel.app
def fn(n, W):
  
if (n==0 or W==0) return 0
if (weight[n-1] <= W):
  op1 = fn(n-1, W-weight[n-1])+value[n-1]
  op2 = fn(n-1, W)
  return max(op1, op2)
  op2= fn(n-1, W)
  return op2



