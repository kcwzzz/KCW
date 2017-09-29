using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class CScenePlayGame : MonoBehaviour
{
    int mCount = 0;
    public CAlberto PFAlberto = null;
    public CEnemy PFSlime = null;
    public CEnemy_1 PFEnemy_1 = null;
    private CAlberto mpAlberto = null;

    List<CEnemy> mEnemyList = null;

    public CUIPlayGame mpUIPlayGame = null;

    // Use this for initialization
    void Start()
    {
        mpUIPlayGame = GameObject.FindObjectOfType<CUIPlayGame>();
        //findObjectOfType 하이어라키 상의 오브젝트를 불러옴
        mpUIPlayGame.SetScene(this);

        mpAlberto = Instantiate<CAlberto>(CRyuGameDataMgr.GetInst().PFAlberto, Vector3.zero, Quaternion.identity);
        mpAlberto.CreateAni();
        mpAlberto.SetScene(this);

        //this.DoCreateEnemy();
        mEnemyList = new List<CEnemy>();

        InvokeRepeating("DoCreateEnemy", 0.0f, 1.0f);
    }

    // Update is called once per frame
    void Update()
    {

    }
    void DoCreateEnemy()
    {

        int tSceneNum = CRyuGameDataMgr.GetInst().SceneLoadNum;

        mCount = mEnemyList.Count;

        if (mEnemyList.Count < CRyuGameDataMgr.GetInst().mStageInfoBundle.mStageInfoList[tSceneNum].mUnitInfoList.Count)
        {
            CEnemy tpSlime = null;
            tpSlime = Instantiate<CEnemy>(CRyuGameDataMgr.GetInst().PFSlime, Vector3.zero, Quaternion.identity);

            tpSlime.transform.position = new Vector3(CRyuGameDataMgr.GetInst().mStageInfoBundle.mStageInfoList[tSceneNum].mUnitInfoList[mCount].mX,
                CRyuGameDataMgr.GetInst().mStageInfoBundle.mStageInfoList[tSceneNum].mUnitInfoList[mCount].mY,
                CRyuGameDataMgr.GetInst().mStageInfoBundle.mStageInfoList[tSceneNum].mUnitInfoList[mCount].mZ);

            tpSlime.SetScene(this);

            mEnemyList.Add(tpSlime);
            mEnemyList[mCount].CreateAni();
            CRyuSoundMgr.GetInst().Play(2);

        }

        /*
        int ti = 0;
        if (mEnemyList.Count < 5)
        {
            ti = mEnemyList.Count;
            CEnemy tpSlime = null;

            tpSlime = null;
            tpSlime = Instantiate<CEnemy>(CRyuGameDataMgr.GetInst().PFSlime, Vector3.zero, Quaternion.identity);
            tpSlime.transform.position = new Vector3(-1.0f * Mathf.Pow(-1, ti) * ti, 0, -1.0f * Mathf.Pow(-1, ti - 1) * ti);
            tpSlime.SetScene(this);
            
            mEnemyList.Add(tpSlime);
            CRyuSoundMgr.GetInst().Play(2);

            mEnemyList[ti].CreateAni();
        }
        else if (5 == mEnemyList.Count)
        {
            CEnemy tpBobby = null;
            tpBobby = null;
            tpBobby = Instantiate<CEnemy>(CRyuGameDataMgr.GetInst().PFBobby, Vector3.zero, Quaternion.identity);
            tpBobby.transform.position = new Vector3(-5, 0, 0);
            tpBobby.SetScene(this);
            tpBobby.SetAlberto(mpAlberto);
            mEnemyList.Add(tpBobby);
            CRyuSoundMgr.GetInst().Play(2);
        }
        else if(6==mEnemyList.Count)
        {
            CEnemy_1 tpEnemy_1= null;
            tpEnemy_1 = null;
            tpEnemy_1 = Instantiate<CEnemy_1>(CRyuGameDataMgr.GetInst().PFEnemy_1, Vector3.zero, Quaternion.identity);
            tpEnemy_1.transform.position = new Vector3(-5, 0, 0);
            tpEnemy_1.SetScene(this);
            tpEnemy_1.SetAlberto(mpAlberto);
            mEnemyList.Add(tpEnemy_1);
            CRyuSoundMgr.GetInst().Play(2);




        }
        */

    }

    public CAlberto GetAlberto()
    {
        return mpAlberto;
    }

    public void OnClickBtnGoScenePlayGame()
    {
        SceneManager.LoadScene("CSceneEmpty");

    }
}
