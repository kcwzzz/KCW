using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CScenePlayGame : MonoBehaviour {

    public CAlberto PFAlberto = null;
    public CEnemy PFSlime = null;

    private CAlberto mpAlberto = null;
    private CEnemy mpSlime = null;

    public CUIPlayGame mpUIPlayGame = null;

	// Use this for initialization
	void Start () {
        mpUIPlayGame = GameObject.FindObjectOfType<CUIPlayGame>();
            //findObjectOfType 하이어라키 상의 오브젝트를 불러옴
        mpUIPlayGame.SetScene(this);

        //mpAlberto = Instantiate<CAlberto>(PFAlberto, Vector3.zero, Quaternion.identity);
        //mpSlime = Instantiate<CEnemy>(PFSlime, Vector3.zero, Quaternion.identity);

        mpAlberto = Instantiate<CAlberto>(CRyuGameDataMgr.GetInst().PFAlberto, Vector3.zero, Quaternion.identity);
        mpSlime = Instantiate<CEnemy>(CRyuGameDataMgr.GetInst().PFSlime, Vector3.zero, Quaternion.identity);
    }

    // Update is called once per frame
    void Update ()
    {
		
	}

    public CAlberto GetAlberto()
    {
        return mpAlberto;
    }

    public CEnemy GetSlime()
    {
        return mpSlime;
    }



}
