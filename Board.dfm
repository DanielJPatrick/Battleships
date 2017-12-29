object Form2: TForm2
  Left = 213
  Top = 106
  Width = 811
  Height = 480
  VertScrollBar.Position = 33
  BiDiMode = bdLeftToRight
  Caption = 'Daniel'#39's BattleShips Program - The BattleField'
  Color = clNavy
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  ParentBiDiMode = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 832
    Top = 55
    Width = 39
    Height = 20
    Caption = 'Chat'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 824
    Top = -9
    Width = 54
    Height = 20
    Caption = 'Status'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 309
    Top = -17
    Width = 118
    Height = 20
    Caption = 'Control Centre'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 104
    Top = 335
    Width = 101
    Height = 20
    Caption = 'Score Board'
    Color = clNavy
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGray
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Visible = False
  end
  object Shape1: TShape
    Left = 224
    Top = 327
    Width = 417
    Height = 41
    Brush.Style = bsClear
    Pen.Color = clWhite
    Visible = False
  end
  object Label5: TLabel
    Left = 248
    Top = 335
    Width = 96
    Height = 20
    Caption = 'Your Score:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label6: TLabel
    Left = 440
    Top = 335
    Width = 146
    Height = 20
    Caption = 'Opponents Score:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object DrawGrid1: TDrawGrid
    Left = 56
    Top = 375
    Width = 625
    Height = 313
    Cursor = crHandPoint
    Color = clBlue
    ColCount = 20
    Ctl3D = True
    DefaultColWidth = 30
    DefaultRowHeight = 30
    DefaultDrawing = False
    FixedCols = 0
    RowCount = 10
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
    ParentCtl3D = False
    TabOrder = 0
    OnDrawCell = DrawGrid1DrawCell
    OnMouseDown = DrawGrid1MouseDown
  end
  object DrawGrid2: TDrawGrid
    Left = 56
    Top = 5
    Width = 625
    Height = 315
    Cursor = crCross
    Color = clBlue
    ColCount = 20
    DefaultColWidth = 30
    DefaultRowHeight = 30
    DefaultDrawing = False
    Enabled = False
    FixedCols = 0
    RowCount = 10
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
    TabOrder = 1
    OnDrawCell = DrawGrid2DrawCell
    OnMouseDown = DrawGrid2MouseDown
  end
  object Chat: TMemo
    Left = 704
    Top = 79
    Width = 297
    Height = 521
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 2
  end
  object Message: TEdit
    Left = 704
    Top = 615
    Width = 297
    Height = 21
    TabOrder = 3
    OnKeyPress = MessageKeyPress
  end
  object Status: TEdit
    Left = 704
    Top = 15
    Width = 297
    Height = 21
    ReadOnly = True
    TabOrder = 4
  end
  object Send: TButton
    Left = 782
    Top = 643
    Width = 137
    Height = 29
    Caption = 'Send'
    TabOrder = 5
    OnClick = SendClick
  end
  object Button1: TButton
    Left = 432
    Top = 343
    Width = 97
    Height = 25
    Caption = 'Next Ship'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 208
    Top = 344
    Width = 97
    Height = 25
    Caption = 'Clear All Ships'
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 320
    Top = 344
    Width = 97
    Height = 25
    Caption = 'Clear Current Ship'
    TabOrder = 8
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 544
    Top = 343
    Width = 97
    Height = 26
    Caption = 'Ready'
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 96
    Top = 343
    Width = 97
    Height = 25
    Caption = 'Randomize Ships'
    TabOrder = 10
    OnClick = Button5Click
  end
  object Score2: TEdit
    Left = 592
    Top = 335
    Width = 25
    Height = 21
    Enabled = False
    TabOrder = 11
    Visible = False
    OnChange = Score2Change
  end
  object Score1: TEdit
    Left = 352
    Top = 335
    Width = 25
    Height = 21
    Enabled = False
    TabOrder = 12
    Visible = False
    OnChange = Score1Change
  end
  object ClientSocket1: TClientSocket
    Active = False
    Address = '127.0.0.1'
    ClientType = ctNonBlocking
    Port = 0
    OnConnecting = ClientSocket1Connecting
    OnConnect = ClientSocket1Connect
    OnRead = ServerSocket1ClientRead
    OnError = ClientSocket1Error
    Left = 14
    Top = 28
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 0
    ServerType = stNonBlocking
    OnListen = ServerSocket1Listen
    OnGetSocket = ServerSocket1GetSocket
    OnClientConnect = ServerSocket1ClientConnect
    OnClientRead = ServerSocket1ClientRead
    Left = 14
    Top = 68
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 120
    object File1: TMenuItem
      Caption = 'File'
      object ExitCurrentGame1: TMenuItem
        Caption = 'Exit Current Game'
        OnClick = ExitCurrentGame1Click
      end
      object ExitBattleShips1: TMenuItem
        Caption = 'Exit BattleShips'
        OnClick = ExitBattleShips1Click
      end
    end
  end
end
