using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

using UnityEngine.SceneManagement;

public class CSceneEvent : MonoBehaviour
{

    public Text mpTxtDialogue = null;

    protected int mCurIndex = 0;

    void Start()
    {
        CGameDataMgr.GetInst().CreateRyu();

        mpTxtDialogue.text = CGameDataMgr.GetInst().mDialogueInfoArray[mCurIndex].mDialogue;

        if (mCurIndex < CGameDataMgr.GetInst().mDialogueInfoArray.Count - 1)
        {
            //mCurIndex++;       
        }


    }
    void  CLoadScene()
    {
        CRyuSoundMgr.GetInst().Play(0);
        SceneManager.LoadScene("CScenePlayGame");
        SceneManager.LoadScene("CSceneGrid_0", LoadSceneMode.Additive);
        SceneManager.LoadScene("CScenePlayGameUI", LoadSceneMode.Additive);
    }


    // Update is called once per frame
    void Update()
    {

    }

    public void OnClickBtnNext()
    {
        mpTxtDialogue.text = CGameDataMgr.GetInst().mDialogueInfoArray[mCurIndex].mDialogue;
        if (mCurIndex < CGameDataMgr.GetInst().mDialogueInfoArray.Count - 1)
        {
            mCurIndex++;
        }
        else
        {
            Invoke("CLoadScene", 2.0f);

        }
    }
}
