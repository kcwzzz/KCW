using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

public class CSceneEmpty : MonoBehaviour
{

    // Use this for initialization
    void Start()
    {        
        SceneManager.LoadScene("CScenePlayGame");
        SceneManager.LoadScene("CScenePlayGameUI", LoadSceneMode.Additive);

        if (0 == CRyuGameDataMgr.GetInst().SceneLoadNum)
        {
            SceneManager.LoadScene("CSceneGrid_1", LoadSceneMode.Additive);
            CRyuGameDataMgr.GetInst().SetSceneNum(1);
        }

        else if(1==CRyuGameDataMgr.GetInst().SceneLoadNum)
        {
            SceneManager.LoadScene("CSceneGrid_0", LoadSceneMode.Additive);
            CRyuGameDataMgr.GetInst().SetSceneNum(0);
        }

    }

    // Update is called once per frame
    void Update()
    {

    }
}
