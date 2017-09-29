﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

public class CSceneEmpty : MonoBehaviour
{

    // Use this for initialization
    void Start()
    {

        Invoke("DoNext", 2.0f);

        //this.DoNext();
    }

    // Update is called once per frame
    void Update()
    {

    }

    void DoNext()
    {

        SceneManager.LoadScene("CScenePlayGame");
        SceneManager.LoadScene("CScenePlayGameUI", LoadSceneMode.Additive);

        if (0 == CRyuGameDataMgr.GetInst().SceneLoadNum)
        {
            CRyuSoundMgr.GetInst().Stop(0);
            CRyuSoundMgr.GetInst().Play(1);
            SceneManager.LoadScene("CSceneGrid_1", LoadSceneMode.Additive);
            CRyuGameDataMgr.GetInst().SetSceneNum(1);
        }

        else if (1 == CRyuGameDataMgr.GetInst().SceneLoadNum)
        {
            CRyuSoundMgr.GetInst().Stop(1);
            CRyuSoundMgr.GetInst().Play(0);
            SceneManager.LoadScene("CSceneGrid_0", LoadSceneMode.Additive);
            CRyuGameDataMgr.GetInst().SetSceneNum(0);
        }
    }

}