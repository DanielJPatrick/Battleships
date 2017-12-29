object Form3: TForm3
  Left = 293
  Top = 140
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Daniel'#39's BattleShips Program - Connection'
  ClientHeight = 253
  ClientWidth = 331
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 72
    Width = 89
    Height = 20
    Caption = 'IP Address'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 16
    Width = 287
    Height = 37
    Caption = 'Connection Details'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 128
    Width = 101
    Height = 20
    Caption = 'Port Number'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 152
    Width = 252
    Height = 13
    Caption = '(Leave blank to use the Recommended one)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 96
    Width = 183
    Height = 13
    Caption = '(Required for Joining to a game)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 120
    Top = 184
    Width = 44
    Height = 16
    Caption = 'Status'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object IP: TEdit
    Left = 120
    Top = 72
    Width = 185
    Height = 21
    TabOrder = 0
  end
  object Port: TEdit
    Left = 120
    Top = 128
    Width = 185
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 48
    Top = 232
    Width = 225
    Height = 25
    Caption = 'Connect'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Status: TEdit
    Left = 16
    Top = 200
    Width = 297
    Height = 21
    ReadOnly = True
    TabOrder = 3
  end
  object MainMenu1: TMainMenu
    object File1: TMenuItem
      Caption = 'File'
      object Back1: TMenuItem
        Caption = 'Back'
        OnClick = Back1Click
      end
      object ExitBattleShips1: TMenuItem
        Caption = 'Exit BattleShips'
        OnClick = ExitBattleShips1Click
      end
    end
  end
end
