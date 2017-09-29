using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEditor;
using System;
using System.Xml;
using System.Xml.Serialization;
using System.IO;
using System.Text;

public class CGameDataMgr
{

    private static CGameDataMgr mInstance = null;
    public List<CDialogueInfo> mDialogueInfoArray = null;

    protected CGameDataMgr()
    {
        mInstance = null;
    }

    public static CGameDataMgr GetInst()
    {
        if (null == mInstance)
        {
            mInstance = new CGameDataMgr();
        }

        return mInstance;
    }

    public void CreateRyu()
    {
        CreateWithDialogue();
    }

    public void CreateWithDialogue()
    {
        mDialogueInfoArray = new List<CDialogueInfo>();
        LoadDialogueInfoArrayFromFile("dialogue_list");
    }

    public bool LoadDialogueInfoArrayFromFile(string tFileName)
    {
        Debug.Log(tFileName);

        TextAsset tTextAsset = null;
        tTextAsset = Resources.Load<TextAsset>(tFileName) as TextAsset;

        if (null == tTextAsset)
        {
            Debug.Log("tTextAsset is null");
            return false;
        }
        else
        {
            Debug.Log(tTextAsset.text);
        }

        XmlDocument Doc = new XmlDocument();
        Doc.LoadXml(tTextAsset.text);

        XmlElement tElementRoot = Doc["DialogueInfoList"];

        foreach (XmlElement tElement in tElementRoot.ChildNodes)
        {
            CDialogueInfo tDialogueInfo = new CDialogueInfo();

            tDialogueInfo.mId = System.Convert.ToInt32(tElement.ChildNodes[0].InnerText);
            tDialogueInfo.mDialogue = tElement.ChildNodes[1].InnerText;

            mDialogueInfoArray.Add(tDialogueInfo);
        }

        return true;
    }

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }
}
