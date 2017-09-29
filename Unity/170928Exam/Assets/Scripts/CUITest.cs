using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class CUITest : MonoBehaviour {

    public Text mpTxtDialogue = null;

    protected int mCurIndex = 0;

    void Start()
    {
        CGameDataMgr.GetInst().CreateRyu();

        mpTxtDialogue.text = CGameDataMgr.GetInst().mDialogueInfoArray[mCurIndex].mDialogue;

        if(mCurIndex < CGameDataMgr.GetInst().mDialogueInfoArray.Count-1)
        {
            mCurIndex++;        
        }
    }

	
	// Update is called once per frame
	void Update ()
    {
	    	
	}

    public void OnClickBtnNext()
    {
        mpTxtDialogue.text = CGameDataMgr.GetInst().mDialogueInfoArray[mCurIndex].mDialogue;
        if(mCurIndex < CGameDataMgr.GetInst().mDialogueInfoArray.Count-1)
        {
            mCurIndex++;
        }
    }
}
