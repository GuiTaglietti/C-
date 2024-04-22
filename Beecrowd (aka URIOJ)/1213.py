'''
    @author GuiTaglietti
    @link   https://judge.beecrowd.com/pt/problems/view/1213
'''
while True:
    try:
        n = int(input())
        base = 1
        ans = 1
        while base % n != 0:
            base = (10 * base + 1) % n
            ans += 1
        print(ans)

    except EOFError:
        break

