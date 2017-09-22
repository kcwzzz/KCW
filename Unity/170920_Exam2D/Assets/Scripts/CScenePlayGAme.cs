using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System;

public class CScenePlayGAme : MonoBehaviour
{
    //PF는 원본
    public CAlberto PFAlberto = null;
    public CSlime PFSlime = null;
    public CRabbit PFRabbit = null;
    public CBullet PFBullet = null;

    //mp는 복사본
    private CAlberto mpAlberto = null;
    
    List<CEnemy> mEnemyList = null;

    public CDxGameOver mpDxGameOver = null;
    public CUIPlayGame mpUIPlayGame = null;

    //가변 배열을 사용해서 하긔

    // Use this for initialization
    void Start()
    {
        Create_Game();
    }

    public void Create_Game()
    {
        int ti = 0;
        int tCount = 0;
        
        mpDxGameOver.CreateRyu();
		mpDxGameOver.SetScene(this);
		mpDxGameOver.Hide();        

        mpUIPlayGame.SetScene(this);

        mpAlberto = null;
        mpAlberto = Instantiate<CAlberto>(PFAlberto, Vector3.zero, Quaternion.identity) as CAlberto;
        mpAlberto.CreateAni();
        mpAlberto.SetScene(this);
            
        CSlime tpSlime = null;
        CRabbit tpRabbit = null;

        mEnemyList = new List<CEnemy>();

        for(int i =1; i < 10; i++)
        {
            tpSlime = null;
            tpSlime = Instantiate<CSlime>(PFSlime, Vector3.zero, Quaternion.identity) as CSlime;
            tpSlime.transform.position = new Vector3(-3.0f * Mathf.Pow(-1,i) *i, 0.0f, 0.0f);
            tpSlime.transform.localScale = new Vector3(Mathf.Pow(-1,i), 1, 1);
            mEnemyList.Add(tpSlime);

            tpRabbit = null;
            tpRabbit = Instantiate<CRabbit>(PFRabbit, Vector3.zero, Quaternion.identity) as CRabbit;
            tpRabbit.transform.position = new Vector3(-6.0f * Mathf.Pow(-1, i) *i, 0.0f, 0.0f);
            tpRabbit.transform.localScale = new Vector3(Mathf.Pow(-1, i), 1, 1);
            mEnemyList.Add(tpRabbit);
        }
        
        tCount = mEnemyList.Count;

        for (ti = 0; ti < tCount; ti++)
        {
            mEnemyList[ti].CreateAni();
            mEnemyList[ti].SetScene(this);

            //mListSlime[ti].SetAlberto(mpAlberto);
            mEnemyList[ti].SetAlive(true);
            mEnemyList[ti].Show();
        }
    }


    public void AlbertoDoAttack(float tDirX)
    {
        if (CAlberto.STATE.IDLE == mpAlberto.GetState())
        {
            this.mpAlberto.transform.localScale = new Vector3(tDirX, 1.0f, 1.0f);

            this.mpAlberto.SetState(CAlberto.STATE.ATTACK);

            this.mpAlberto.DoState();


        }
    }

    public CAlberto GetAlberto()
    {
        return mpAlberto;
    }

    // Update is called once per frame
    void Update()
    {

    }
}
