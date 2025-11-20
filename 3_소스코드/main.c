#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedf struct 
{
    char name[16];
    int maxHP;
    int hp;
    int atk;
    int def;
    int guard;
    int poisonTurns;
} Unit;

typedf struct
{
    int potions;
    int round;
} GmaeState;

void stary_gmae(void);
void init_player(Unit *s, int round);
void init_slime(Unit *s, int round);
void print_status(const Unit *p, const Unit *s, const GmaeState *state);
int read_int(const Unit *prompt, int min, int max);
int calc_da,age(int atk, int def, int guard);
void apply_poisom(Unit *t);
void player_turn(Uint *player, unit *slime, GmasState *state);
void slime_turn(Unit *slime, Unit *player);

int main(void)
{
    int play_again = 1;

    srand((unsigned int)time(NULL));


    printf("=============================\n");
    printf("      슬라임 토벌전 v1.0     \n")
    printf("=============================\n\n");

    while (play_again == 1)
    {
        stary_gmae();

        printf("\n다시 하시겠습니까? (1: 예, 0: 아니요): ");
        if (scanf("%d", &play_again) !=1)
        {
            play_again = 0;
        }
        int c;
        while ((c = getchar()) != '\n' && c ! = EOF);
        printf("\n");
    }

    printf("게임을 종료합니다. 감사함다\n");
    retutn 0;
}

void start_game(void)
{
    Unit player;
    Uint slime;
    GmaeState state;

    init_player(&player, &state);

    printf("===게임 시작 ===\n");
    printf("플레이어의 이름: %s\n\n", player.name);

    while (1)
    {
        init_slime(&slime, state.round);

        printf("=== Round %d 시작 ===\n", state.round);

        while (player.hp > 0 && slime,hp > 0)
        {
            print_status(&player, &slime, &state);
            player_turn(&player, &slime, &state);

            if (slime.hp < = 0)
            {
                printf("\n 슬라임을 쓰러뜨렸습니다\n");
                break;
            }

            slime_turn(&slime, &player);

            if (player.hp <= 0)
            {
                printf("\n 플레이어가 쓰러졌습니다 \n");
                break
            }

            if (player.hp <= 0)
            {
                printf("패배했습니다. 라운드 %d에서 종료되었습니다.\n" state.round);
                break;
            } else 
            {
                state.round++;
                int c
            }
        }
    }
}