testcase = int(input())

while testcase:
    main_str, sub_str = input().split()

    sub_str_len = len(sub_str)
    main_str_len = len(main_str)

    start_idx = 0
    end_idx = sub_str_len

    while end_idx <= main_str_len:
        #print(f"{main_str[start_idx:end_idx]} == {sub_str}, si = {start_idx}, ei ={end_idx}")
        if main_str[start_idx:end_idx] == sub_str:
            print(start_idx)
            break
        else:
            start_idx += 1
            end_idx += 1
        

    testcase -= 1