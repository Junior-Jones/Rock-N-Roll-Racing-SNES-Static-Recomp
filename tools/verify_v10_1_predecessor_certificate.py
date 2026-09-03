from __future__ import annotations
import argparse,hashlib,json,subprocess
from pathlib import Path
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--project',type=Path,required=True);p.add_argument('--rom',type=Path,required=True);p.add_argument('--starter-zip',type=Path,required=True);p.add_argument('--oracle-zip',type=Path,required=True);p.add_argument('--certificate',type=Path,required=True);a=p.parse_args();c=json.loads(a.certificate.read_text())
 assert sha(a.rom)==c['rom_sha256'];assert sha(a.starter_zip)==c['starter_sha256'];assert sha(a.oracle_zip)==c['oracle_sha256']
 for rel,want in c['files'].items():
  assert hashlib.sha256((a.project/rel).read_bytes()).hexdigest()==want,rel
 if (a.project/'.git').exists():
  got=subprocess.check_output(['git','-C',str(a.project),'rev-parse',f"{c['git_tag']}^{{commit}}"],text=True).strip();assert got==c['git_commit'],(got,c['git_commit'])
  for rel,want in c['files'].items():
   frozen=subprocess.check_output(['git','-C',str(a.project),'show',f"{c['git_tag']}:{rel}"])
   assert hashlib.sha256(frozen).hexdigest()==want,rel
 print(f"V10.1 predecessor certificate: PASS ({len(c['files'])} frozen V09 files)")
if __name__=='__main__':main()
