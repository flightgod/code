# variables
$reg="HKCU:\Software\Microsoft\Office\15.0\Outlook\Profiles"
$child=(Get-ChildItem -Path $reg).name

Function DeleteProfiles {
    Write-Host "All profiles removed successfully" -ForegroundColor Green
    foreach($item in $child)
    {
        Remove-item -Path registry::$item -Recurse #-ErrorAction Inquire -WhatIf
    }
}

Function CloseOutlook {
    if($process=(get-process 'outlook' -ErrorAction SilentlyContinue))
    {
        Write-Host "Outlook is running so close it.." -ForegroundColor Green
        kill($process)
        Write-Host "Outlook is stopped " -ForegroundColor Green
    }
}

Function CreateBlankProfile {
    Write-Host "Now create new profile for outlook" -ForegroundColor Green
    New-Item -Name "NewCrap" -Path $reg -Force -Verbose
}


Function OpenNewProfile {
Write-Host "Launch outlook with newly created profile" -ForegroundColor Green
    Start-Process 'outlook' -ErrorAction SilentlyContinue -ArgumentList '/profile "NewCrap" '
}

CloseOutlook