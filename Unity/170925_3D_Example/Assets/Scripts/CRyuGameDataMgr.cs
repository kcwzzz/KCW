using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CRyuGameDataMgr
{
    private static CRyuGameDataMgr mInstance = null;

    public CAlberto PFAlberto = null;
    public CEnemy PFSlime = null;
    public int SceneLoadNum = 0;


    protected CRyuGameDataMgr()
    {
        mInstance = null;
    }

    public static CRyuGameDataMgr GetInst()
    {
        if(null == mInstance)
        {
            mInstance = new CRyuGameDataMgr();
        }

        return mInstance;
    }

    public void SetSceneNum(int tInt)
    {
        SceneLoadNum = tInt;
    }

    public void CreateRyu()
    {
        //load prefabs
        PFAlberto = Resources.Load<CAlberto>("Prefabs/PFAlberto");
        PFSlime = Resources.Load<CEnemy>("Prefabs/PFSlime");
    }

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
