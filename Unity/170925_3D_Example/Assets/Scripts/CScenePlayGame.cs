using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class CScenePlayGame : MonoBehaviour
{

    public CAlberto PFAlberto = null;
    public CEnemy PFSlime = null;

    private CAlberto mpAlberto = null;
    //private CEnemy mpSlime = null;

    List<CEnemy> mEnemyList = null;

    public CUIPlayGame mpUIPlayGame = null;

    // Use this for initialization
    void Start()
    {
        int tCount = 0;

        mpUIPlayGame = GameObject.FindObjectOfType<CUIPlayGame>();
        //findObjectOfType 하이어라키 상의 오브젝트를 불러옴
        mpUIPlayGame.SetScene(this);

        mpAlberto = Instantiate<CAlberto>(CRyuGameDataMgr.GetInst().PFAlberto, Vector3.zero, Quaternion.identity);
        mpAlberto.CreateAni();
        mpAlberto.SetScene(this);


        //mpSlime = Instantiate<CEnemy>(CRyuGameDataMgr.GetInst().PFSlime, Vector3.zero, Quaternion.identity);

        CEnemy tpSlime = null;

        mEnemyList = new List<CEnemy>();

        for (int ti = 1; ti < 5; ti++)
        {
            tpSlime = null;
            tpSlime = Instantiate<CEnemy>(CRyuGameDataMgr.GetInst().PFSlime, Vector3.zero, Quaternion.identity);
            tpSlime.transform.position = new Vector3(-1.0f * Mathf.Pow(-1, ti) * ti, 0, -1.0f * Mathf.Pow(-1, ti-1) * ti);
            tpSlime.SetScene(this);
            mEnemyList.Add(tpSlime);

        }

        tCount = mEnemyList.Count;

        for (int i = 1; i < tCount; i++)
        {
            mEnemyList[i].CreateAni();
        }
    }

    // Update is called once per frame
    void Update()
    {

    }

    public CAlberto GetAlberto()
    {
        return mpAlberto;
    }

    public void OnClickBtnGoScenePlayGame()
    {
        SceneManager.LoadScene("CSceneEmpty", LoadSceneMode.Additive);
    }
}
