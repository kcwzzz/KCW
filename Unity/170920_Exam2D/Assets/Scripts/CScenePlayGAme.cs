using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System;

public class CScenePlayGAme : MonoBehaviour
{
    //PF는 원본
    public CAlberto PFAlberto = null;
    public CSlime PFSlime = null;

    //mp는 복사본
    private CAlberto mpAlberto = null;
    List<CSlime> mListSlime = null;

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
        /*
        mpDxGameOver.CreateRyu();
		mpDxGameOver.SetScene(this);
		mpDxGameOver.Hide();

        
        Vector3 tVector = new Vector3(-2.0f, 0.0f, 0.0f);
        Vector3 tVector_0 = new Vector3(2.0f, 0.0f, 0.0f);
        */

        mpUIPlayGame.SetScene(this);

        mpAlberto = null;
        mpAlberto = Instantiate<CAlberto>(PFAlberto, Vector3.zero, Quaternion.identity) as CAlberto;
        mpAlberto.CreateAni();
        mpAlberto.SetScene(this);

        CSlime tpSlime = null;

        mListSlime = new List<CSlime>();

        tpSlime = null;
        tpSlime = Instantiate<CSlime>(PFSlime, Vector3.zero, Quaternion.identity) as CSlime;
        tpSlime.transform.position = new Vector3(-3.0f, 0.0f, 0.0f);
        mListSlime.Add(tpSlime);

        tpSlime = null;
        tpSlime = Instantiate<CSlime>(PFSlime, Vector3.zero, Quaternion.identity) as CSlime;
        tpSlime.transform.position = new Vector3(3.0f, 0.0f, 0.0f);
        mListSlime.Add(tpSlime);

        tCount = mListSlime.Count;
        for(ti=0; ti<tCount; ti ++ )
        {
            mListSlime[ti].CreateAni();
            mListSlime[ti].SetScene(this);

            //mListSlime[ti].SetAlberto(mpAlberto);
            mListSlime[ti].SetAlive(true);
            mListSlime[ti].Show();
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

    // Update is called once per frame
    void Update()
    {

    }
}
