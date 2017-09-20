using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CTestArray : MonoBehaviour
{
    int tRow = 0;           //던전 Row
    int tCol = 0;           //던전 Col

    int tRouteNum = 0;      //던전 내 Route Array의 숫자
    int tDiceNumber = 0;     //주사위 숫자

    int tActor_Row = 0;     //Actor 위치의 Row
    int tActor_Col = 0;     //Actor 위치의 Col

    int[,] tArray;
    int[] tArray_Route;

    int tBoss_Row = 0;
    int tBoss_Col = 0;
    int tEndCount = 0;

    int tRSPGameCount = 0;
    int tActor_WinCount = 0;
    int tEnemy_WinCount = 0;

    public GameObject mpBtnDiceRoll = null;
    public GameObject mpRCPGame_RockBtn = null;
    public GameObject mpRCPGame_SissorBtn = null;
    public GameObject mpRCPGame_PaperBtn = null;



    // Use this for initialization
    void Start()
    {
        mpRCPGame_RockBtn.gameObject.SetActive(false);
        mpRCPGame_SissorBtn.gameObject.SetActive(false);
        mpRCPGame_PaperBtn.gameObject.SetActive(false);

        this.MakeArray();
        this.MakeRoute();
    }

    public void MakeArray()
    {
        Debug.Log("@rectangular array");
        // 던전 2차원 배열 생성
        tArray = new int[,]
            {
                { 1, 1, 1, 0, 0 },
                { 0, 0, 1, 0, 0 },
                { 0, 0, 1, 1, 0 },
                { 0, 0, 0, 1, 0 },
                { 0, 0, 0, 1, 2 }
        };
    }


    public void MakeRoute()
    {
        tArray_Route = new int[15];
        int ti = 0;

        for (tRow = 0; tRow < tArray.GetLength(0); tRow++)
        {
            for (tCol = 0; tCol < tArray.GetLength(1); tCol++)
            {
                if (0 != tArray[tRow, tCol])
                {
                    tArray_Route[ti++] = tRow * 10 + tCol;

                    if (2 == tArray[tRow, tCol])
                    {
                        tEndCount = ti;

                    }
                }

            }
        }
    }

    public void OnClickBtnDice()
    {
        Debug.Log("Dice Roll");

        tDiceNumber = Random.Range(1, 7);
        Debug.Log("Dice Number : " + tDiceNumber);

        this.ActorMove();
    }

    public void RSPGAme_BtnROCK()
    {
        //Rock = 1
        Debug.Log("ROCK");

        int tEnemy = Random.Range(1, 4);
        if (1 == tEnemy)
        {
            Debug.Log("Enemy : Rock");
            Debug.Log("Draw");
        }
        else if (2 == tEnemy)
        {
            Debug.Log("Enemy : Sissors");
            Debug.Log("You Win");
            tActor_WinCount += 1;
        }
        else
        {
            Debug.Log("Enemy : Paper");
            Debug.Log("You Lose");
            tEnemy_WinCount += 1;
        }
        tRSPGameCount += 1;
        this.CountScore();
    }

    public void RSPGAme_BtnSissors()
    {
        //Sissors = 2
        Debug.Log("Sissors");


        int tEnemy = Random.Range(1, 4);
        if (1 == tEnemy)
        {
            Debug.Log("Enemy : Rock");
            Debug.Log("You Lose");
            tEnemy_WinCount += 1;
        }
        else if (2 == tEnemy)
        {
            Debug.Log("Enemy : Sissors");
            Debug.Log("Draw");
        }
        else
        {
            Debug.Log("Enemy : Paper");
            Debug.Log("You Win");
            tActor_WinCount += 1;
        }
        tRSPGameCount += 1;

        this.CountScore();
    }

    public void RSPGAme_BtnPaper()
    {
        //Paper =3;
        Debug.Log("Paper");


        int tEnemy = Random.Range(1, 4);
        if (1 == tEnemy)
        {
            Debug.Log("Enemy : Rock");
            Debug.Log("You Win");
            tActor_WinCount += 1;
        }
        else if (2 == tEnemy)
        {
            Debug.Log("Enemy : Sissors");
            Debug.Log("You Lose");
            tEnemy_WinCount += 1;
        }
        else
        {
            Debug.Log("Enemy : Paper");
            Debug.Log("Draw");
        }
        tRSPGameCount += 1;

        this.CountScore();
    }

    public void ActorMove()
    {
        if (tRouteNum + tDiceNumber < tEndCount)
        {
            tRouteNum += tDiceNumber;
        }
        else
        {
            tRouteNum = tEndCount - 1;
        }

        tActor_Row = tArray_Route[tRouteNum] / 10;
        tActor_Col = tArray_Route[tRouteNum] % 10;

        Debug.Log("tRouteNum : " + tArray_Route[tRouteNum]);
        Debug.Log("Actor Cur Location : " + tRouteNum);
        //Debug.Log("tActor_Row : " + tActor_Row);
        //Debug.Log("tActor_Col : " + tActor_Col);

        if (tRouteNum == tEndCount - 1)
        {
            mpBtnDiceRoll.gameObject.SetActive(false);
            mpRCPGame_RockBtn.gameObject.SetActive(true);
            mpRCPGame_SissorBtn.gameObject.SetActive(true);
            mpRCPGame_PaperBtn.gameObject.SetActive(true);

            Debug.Log("Meet Boss");
        }
    }

    public void CountScore ()
    {
        if (5 <= tRSPGameCount)
        {
            Debug.Log("Game Set");
            Debug.Log("Actor Win : " + tActor_WinCount  + "  vs  " + "Enemy Win : " + tEnemy_WinCount);

            if(tActor_WinCount > tEnemy_WinCount)
            {
                Debug.Log("Actor Win");

            }
            else if(tActor_WinCount < tEnemy_WinCount)
            {
                Debug.Log("Enemy Win");
            }
            else
            {
                Debug.Log("Draw Game");
            }

            mpRCPGame_RockBtn.gameObject.SetActive(false);
            mpRCPGame_SissorBtn.gameObject.SetActive(false);
            mpRCPGame_PaperBtn.gameObject.SetActive(false);

        }
        Debug.Log("Battle count : " + tRSPGameCount);
        Debug.Log("Actor Win count : " + tActor_WinCount);
        Debug.Log("Enemy Win count : " + tEnemy_WinCount);
    }
    void Update()
    {

    }

}

