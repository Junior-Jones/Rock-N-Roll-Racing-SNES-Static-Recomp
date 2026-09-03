from __future__ import annotations
import argparse,hashlib,json,subprocess
from pathlib import Path
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--project',type=Path,required=True);p.add_argument('--rom',type=Path,required=True);p.add_argument('--starter-zip',type=Path,required=True);p.add_argument('--oracle-zip',type=Path,required=True);p.add_argument('--certificate',type=Path,required=True);a=p.parse_args();c=json.loads(a.certificate.read_text())
 assert sha(a.rom)==c['rom_sha256'];assert sha(a.starter_zip)==c['starter_sha256'];assert sha(a.oracle_zip)==c['oracle_sha256']
 for rel,h in c['files'].items():assert sha(a.project/rel)==h,rel
 if (a.project/'.git').exists():
  assert subprocess.check_output(['git','-C',str(a.project),'rev-parse',c['git_tag']+'^{}']).decode().strip()==c['git_commit']
  for rel,h in c['files'].items():assert hashlib.sha256(subprocess.check_output(['git','-C',str(a.project),'show',f"{c['git_tag']}:{rel}"])).hexdigest()==h,rel
 print(f"V09C PREDECESSOR: PASS tag={c['git_tag']} files={len(c['files'])}")
if __name__=='__main__':main()
