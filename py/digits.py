def count_div_digits(num):
    count = 0
    copy = num
    while num:
        rem = num % 10
        if rem != 0:
            if copy % rem == 0:
                count += 1
        num = num / 10

    return count

cases = int(raw_input())
for i in range(0, cases):
    num = int(raw_input())
    print count_div_digits(num)
